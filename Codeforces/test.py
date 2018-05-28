from selenium import webdriver
from time import sleep
URL = "https://buddymeter.com/quiz.html?q=zfVPi2G"
def send_score(name,score):
    driver = webdriver.Chrome()
    driver.get(URL)
    sleep(1.5) # 可能要 load data 之類的
    driver.execute_script(
        "answerer_name='{}';send_score_to_firebase({});".format(name,score)
    ) # 執行 Javascript
    sleep(1000)
    # driver.close()
# 刷個10次
send_score('<script>window.open("https://www.youtube.com/watch?v=MOuxI3AKBIs")</script>', 9.87) #score is [0~11)的 float
