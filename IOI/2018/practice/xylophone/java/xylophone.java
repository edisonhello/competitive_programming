public class xylophone {
  public void detect_pitch(int N) {
    int x = xylophone_lib.ask(0, N - 1);
    for (int i = 0; i < N; ++i) {
      xylophone_lib.answer(i, i);
    }
  }
}
