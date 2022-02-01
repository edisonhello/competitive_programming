#pragma once
#ifndef THREAD_POOL_C
#define THREAD_POOL_C

#include <vector>
#include <queue>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

namespace std {

	class threadpool {
		using Task = std::function<void()>;
		std::vector<std::thread> pool;
		std::queue<Task> tasks;
		std::mutex m_lock;
		std::condition_variable cv_task;
		std::atomic<bool> stoped;
		std::atomic<int>  idlThrNum;

		public:
		inline threadpool(unsigned short size = 4) :stoped{ false } {
			idlThrNum = size < 1 ? 1 : size;
			for (size = 0; size < idlThrNum; ++size) {
				pool.emplace_back( [this] { 
					while (!this->stoped) {
						std::function<void()> task; 
						{ 
							std::unique_lock<std::mutex> lock{ this->m_lock };
							this->cv_task.wait(lock, [this] {
								return this->stoped.load() || !this->tasks.empty();
							});
							if (this->stoped && this->tasks.empty()) return;
							task = std::move(this->tasks.front()); // 取一個 task
							this->tasks.pop();
						}
						idlThrNum--;
						task();
						idlThrNum++;
					}
				});
			}
		}

		inline ~threadpool() {
			stoped.store(true);
			cv_task.notify_all();
			for (std::thread& thread : pool) {
				if (thread.joinable())
					thread.join(); 
			}
		}

		public:

		// 提交一個任務
		// 呼叫.get()獲取返回值會等待任務執行完,獲取返回值
		// 有兩種方法可以實現呼叫類成員，
		// 一種是使用   bind： .commit(std::bind(&Dog::sayHello, &dog));
		// 一種是用 mem_fn： .commit(std::mem_fn(&Dog::sayHello), &dog)
		template<class F, class... Args>
		auto commit(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {
			if (stoped.load()) 
				throw std::runtime_error("commit on ThreadPool is stopped.");

			using RetType = decltype(f(args...));
			auto task = std::make_shared<std::packaged_task<RetType()>>(
				std::bind(std::forward<F>(f), std::forward<Args>(args)...)
			);  
			std::future<RetType> future = task->get_future(); 
			{
				std::lock_guard<std::mutex> lock{ m_lock };
				tasks.emplace( [task]() { (*task)(); });
			}
			cv_task.notify_one(); 

			return future;
		}

		int idlCount() { return idlThrNum; }
	};

}

#endif
