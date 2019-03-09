/* KochCurve(コッホ曲線) */

//Program16_1_点を表す構造体
typedef struct Point{double x,y;}Point;

//Program16_2_ベクトルを表す構造体
typedef Point Vector;

//Program16_3_線分を表す構造体
struct Segment{
  Point p1, p2;
}Segment;

//Program16_4_直線を表す構造体(線分と同じ)
typedef Segment Line;

//Program16_5_円を表す構造体
tyoedef struct Circle{
  Point c; //center
  double r; //半径
}Circle;

//Program16_6_多角形の表現
typedef Vector Polygon; //要確認

//Program16_7_ベクトルに対する演算子の定義
Point operator_Plus(Vector j,Vector k){
  return Point(j.x + k.x, j.y + k.y );
}

Point operator_Minus(Vector j,Vector k){
  return Point(j.x - k.x, j.y - k.y );
}

Point operator_Multiply(Vector j,double k){
  return Point(j.x * k, j.y * k );
}

//Program16_8_ベクトルに対する演算の例
vector a, b, c, d;
c = operator_Minus(a,b);
d = operator_Minus(a, 2.0);

//Program16_9_ベクトルaの大きさ
double norm(Vector a){
  return a.x * a.x + a.y * a.y; //大きさの二乗を返す（平方根の中身）
}

double abs(Vector a){
  return sqrt(norm (a)); //平方根
}

//Program16_11_ベクトルaとベクトルbの内積
double dot(Vector a, Vector b){
  return a.x* b.x + a.y*b.y;
}

//Program16_12_ベクトルの外積
double cross(Vector a, Vector b){
  return a.x* b.y - a.y*b.x;
}

//Program16_13_ベクトルaとbの直交判定
bool isOrthogonal_00(Vector a, Vector b){
  return equals(dot(a,b),0.0); //内積が０の時は直行してるよね
}

//線分から調べる場合
bool isOrthogonal_01(Segment a,Segment b){
  Vector Vec_a, Vec_b;
  Vector Vec_a.x = a.p1.x-a.p2.x; //線分の差からVectorを求めている。
  Vector Vec_a.y = a.p1.y-a.p2.y; //線分の差からVectorを求めている。
  Vector Vec_b.x = b.p1.x-b.p2.x; //線分の差からVectorを求めている。
  Vector Vec_b.y = b.p1.y-b.p2.y; //線分の差からVectorを求めている。
  return equals(dot(Vec_a,Vec_b),0.0); //内積が０の時は直行してるよね
}

//Program16_14_ベクトルaとbの平行判定
bool isParallel(Vector a, Vector b){
  return equals(cross(a,b),0.0);
}

//Program16_15_射影
//xの座標をbaseと射影の比率から求める。
Point project(Segment s,Point p){ //線分sとある点pのによるsへの垂線
  Vector base =  operator_Minus(s.p2,s.p1);  //線分sの終点-始点
  double r = dot(operator_Minus(p, s.p1),base)/norm(base) //t(p1からの射影点までの距離)とbaseの比率
  return operator_Plus(s.p1,base*r); //baseはp2-p1
}

//Program16_16_反射
Point reflect(Segment s,Point p){
  return operator_Plus(p ,(operator_Multiply(operator_Minus(project(s,p), p),2.0))); //ある点pからの射影までのベクトルを２倍する
}

//Program16_17_距離(点aと点bの距離)
double getDistance(Point a,Point b){
  return abs(operator_Minus(b,a));
}

//Program16_17_距離(点aと直線の距離)
double getDistanceLP(Line l,Point p){ // 外積(面積)/底辺の長さで点と直線の距離が出る
  return abs(cross(operator_Minus(l.p2,l.p1),operator_Minus(p,l.p1))/abs(operator_Minus(l.p2,l.p1)))
}
