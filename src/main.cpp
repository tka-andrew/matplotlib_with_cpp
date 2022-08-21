#include <matplotlibcpp.h>

#include <vector>

namespace plt = matplotlibcpp;

int main() {

  //Graph Format
  plt::title("Sample Figure");
  plt::xlabel("y label example");
  plt::ylabel("x label example");
  plt::xlim(0, 10);
  plt::ylim(0, 10);

  std::vector<double> x = {1, 2, 3, 4};
  std::vector<double> y = {5, 2, 4, 8};
  plt::plot(x,y, {{"linewidth", "5"}});

  std::vector<double> x2 = {5, 6, 6.9, 8.12};
  std::vector<double> y2 = {1.5, 6.3, 7.1, 8.4};
  plt::plot(x2, y,{{"color", "magenta"}, {"marker", "*"}, {"linestyle", "--"}});
  
  plt::plot({0.5}, {0.5}, {{"color", "green"}, {"marker", "x"}, {"markersize", "12"}});

  std::vector<std::vector<double>> redSquares{{1.5,1.5}, {2.5, 2.5}, {1.5, 3.5}};
  int n = redSquares.size();
  for (int i = 0; i<n; i++)
  {
    plt::plot({redSquares[i][0]}, {redSquares[i][1]}, {{"color", "red"}, {"marker", "s"}, {"markersize", "10"}});
  }

  plt::show();
}