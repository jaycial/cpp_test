//
//  main.cpp
//  test_cpp
//
//  Created by 国杰佟 on 2017/12/4.
//  Copyright © 2017年 佟国杰. All rights reserved.
//

#include <iostream>
int rand_take_five_num_from_ten();
int main(int argc, const char * argv[]) {
    int option = 0;
    std::cout << "请选择功能:\n";
    std::cout << "1:打印十个数字中随机的五个（双色球）:\n";
    std::cout << "0:退出程序:\n";
    std::cin >> option;
    while (option > 0) {
        switch (option) {
            case 1:
                rand_take_five_num_from_ten();
                break;
            default:
                break;
        }
        std::cout << "请选择功能:";
        std::cin >> option;
    }
}
//用户输入十个数字，从中随机取五个
int rand_take_five_num_from_ten()
{
    int a[10];
    int res_position[5];
    int tmp_position = 0;
    bool is_repeated = false;
    std::cout << "请给十个数赋初值：";
    std::cin >> a[0];
    for (int i=1; i<10; i++) {
        std::cout << "已赋值" << i << "个，请继续：";
        std::cin >> a[i];
    }
    std::cout << "赋值完成\n取出的五个随机数为：";
    for (int i=0; i<5; i++) {
        is_repeated = false;
        tmp_position = rand()%10;
        for (int j=0; j<=i; j++) {
            if(tmp_position == res_position[i]){
                is_repeated = true;
                break;
            }
        }
        while (is_repeated) {
            is_repeated = false;
            tmp_position = rand()%10;
            for (int j=0; j<i; j++) {
                if(tmp_position == res_position[i]){
                    is_repeated = true;
                    break;
                }
            }
        }
        res_position[i] = tmp_position;
    }
    //打印数组
    for (int i=0; i<5; i++) {
        std::cout << a[res_position[i]] << "\t";
    }
    std::cout << "打印结束\n";
    return 0;
}
