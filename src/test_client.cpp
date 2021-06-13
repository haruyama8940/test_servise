/* クライアント */
#include <ros/ros.h>                        // ROSヘッダファイル
#include <std_srvs/SetBool.h>                 // サービスヘッダファイル

int main(int argc, char **argv) {
  ros::init(argc, argv, "test_client");        // ノードの初期化（ノード名を"clt_test"に設定）
  ros::NodeHandle nh;                       // ノードハンドルの生成
  ros::ServiceClient testClient = nh.serviceClient<std_srvs::SetBool>("service_call");  // クライアントの生成
  std_srvs::SetBool::Request req;             // リクエストの生成
  std_srvs::SetBool::Response resp;           // レスポンスの生成
  req.data=10;
  bool result = testClient.call(req, resp); // リクエストの送信
  if(result) ROS_INFO_STREAM("Recive response!");     // レスポンス受信の表示
  else ROS_INFO_STREAM("Error!");
}
