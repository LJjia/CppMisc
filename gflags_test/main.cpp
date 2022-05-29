#include <iostream>
#include <string>
#include <glog/logging.h>
#include <sys/stat.h>
#include <gflags/gflags.h>


#include <gtest/gtest.h>
//wait for testing
int add(int a, int b) {
    return a + b;
}
//声明testCase组，测试testAdd函数
TEST(testCase, testAdd) {
EXPECT_EQ(add(1, 2), 3) << " msg";// <<如果测试不过，则输出对应信息
EXPECT_EQ(add(3, 5), 4) << "fail!";
ASSERT_STREQ("1", "1");//断言
}
//同样在testCase组下，测试tt
TEST(testCase, tt) {
ASSERT_STREQ("", "");
}

DEFINE_string(your_name,"","input name");


static bool ValidateAge(const char* flagname, int32_t value) {
    printf("call age param check\n");
    if (value > 0 && value < 200)
        return true;
    printf("Invalid value for --%s: %d\n", flagname, (int)value);
    return false;
}
DEFINE_int32(age, 18, "your age");
// 使用全局 static 变量来注册函数，static 变量会在 gflags::ParseCommandLineFlags时调用
// 检查参数会在gflags::ParseCommandLineFlags时执行,如果没有传入对应参数,则将会以默认参数
// 进行参数判断
static const bool flags_check_age = gflags::RegisterFlagValidator(&FLAGS_age, &ValidateAge);


void OtherFunc();


int main(int argc,char * argv[]) {
    std::cout << "Hello, World!" << std::endl;
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    std::cout<<"====func parse end====\n";
    int num=100;
    google::InitGoogleLogging(argv[0]);
    std::string log_dir="logs_dir";
    if (access (log_dir.c_str(),0) == -1)
    {
        std::cerr << "LogDir Not Exist,We Will Create!" << std::endl;
        mkdir(log_dir.c_str(),  S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
    // 屏蔽掉保存日志到文件中,仅输出屏幕,保存文件到日志中配置复杂...
    // FLAGS_log_dir = log_dir; //设置日志文件输出目录
    FLAGS_alsologtostderr = true; //日志记录到文件的同时输出到标准输出
    FLAGS_max_log_size = 10; //最大日志大小（MB）, 如果设置为0将默认为1
    FLAGS_colorlogtostderr = true; // 设置记录到标准输出的颜色消息（如果终端支持）


    DLOG(INFO) << "debug log level msg";
    LOG(INFO) << "Found " << num << " num";
    LOG(INFO) << "second line ";
    LOG(WARNING) << "warning msg";
    LOG(ERROR) << "end main proc";

    LOG(INFO) << "glags param name "<<FLAGS_your_name<<std::endl;
    LOG(INFO) << "glags param age "<<FLAGS_age<<std::endl;
    OtherFunc();

    testing::InitGoogleTest(&argc, argv);
    int ret=RUN_ALL_TESTS();
    return 0;
}