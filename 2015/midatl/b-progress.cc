#include <bits/stdc++.h>

using namespace std;

double d, h, x;
double n1, n2;

double getDist(double ang1) {
  double radAng1 = ang1*M_PI/180;
  double radAng2 = asin(sin(radAng1) * n2 / n1);

  double maybeDist = tan(radAng1) * d +  tan(radAng2) * h;
  //cout << radAng1*360/(2*PI) << "-" << radAng2*360/(2*PI) << " : " << maybeDist << endl;
  return maybeDist;
}

int main() {

  while (cin >> d >> h >> x >> n1 >> n2 && d && h && x && n1 && n2) {
    double low = 0;
    double max = 90;

    double med = (low + max)/2;

    while (true) {
      double testVal = getDist(90 - med);
      //printf("yay at %.8lf got %.8lf\n", med, testVal);

      if (testVal - x < 0.0000001 && testVal - x > -0.0000001) {
        printf("%.2lf\n", med);
        break;
      }
      else if (testVal < x)
        max = med;
      else if (testVal > x)
        low = med;

      med = (low + max)/2;
    }
  }
}
