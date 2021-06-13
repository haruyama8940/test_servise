/* サーバー */
#include <ros/ros.h>                        // ROSヘッダファイル
#include <std_srvs/SetBool.h>                 // サービスヘッダファイル

bool serviceCallBack(std_srvs::SetBool::Request &req,
std_srvs::SetBool::Response &resp) {          // リクエスト受信時に呼ばれるコールバック関数
  ROS_INFO_STREAM("Recive Request!");       // 標準出力へリクエスト受信を表示
  if (req.data==10)
  {
    ROS_INFO("%d",req.data);
  }
  
  return true;                              // レスポンスの戻り値
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "test_server");        // ノードの初期化（ノード名を"srv_test"に設定）
  ros::NodeHandle nh;                       // ノードハンドルの生成
  ros::ServiceServer srv = nh.advertiseService("service_call", &serviceCallBack);  // サーバー生成とコールバック関数の登録
  ROS_INFO_STREAM("Service ready!");
  ros::spin();                              // リクエストの無限待ち
}
