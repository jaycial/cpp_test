//
//  main.cpp
//  test_cpp
//
//  Created by 国杰佟 on 2017/12/4.
//  Copyright © 2017年 佟国杰. All rights reserved.
//

#include <iostream>
int rand_take_five_num_from_ten();
int insert_sort_arr();
int main(int argc, const char * argv[]) {
    int option = 0;
    std::cout << "请选择功能:\n";
    std::cout << "1:抽签题:\n";
    std::cout << "2:插入排序:\n";
    std::cout << "0:退出程序:\n";
    std::cin >> option;
    while (option > 0) {
        switch (option) {
            case 1:
                rand_take_five_num_from_ten();
                break;
            case 2:
                insert_sort_arr();
                break;
            default:
                break;
        }
        std::cout << "请选择功能:";
        std::cout << "1:抽签题:\n";
        std::cout << "2:插入排序:\n";
        std::cout << "0:退出程序:\n";
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

//已有10个按增序排列好的整数1，3，5，7，9，11，13，15，17，19。要求把一个整数n插到数组中，保持增序排列。
int insert_sort_arr()
{
    int a[10] = {1,3,5,7,9,11,13,15,17,19};
    int res_arr[11];
    int insert_value;
    int insert_pos = 0; //插入位置
    //打印原始数组
    std::cout << "原始数组为：";
    for (int i=0; i<10; i++) {
        std::cout << a[i] << "\t";
    }
    std::cout << "\n";
    std::cout << "现在请输入要插入的数值：";
    std::cin>>insert_value;
    //判断插入位置
    if(insert_value <= a[0]){
        insert_pos = 0;
    }else if(insert_value >= a[9]){
        insert_pos = 10;
    }else{
        //二分法查找
        if(insert_value > a[4]){
            for (int i=4; i<9; i++) {
                if((a[i]< insert_value) && (insert_value <= a[i+1])){
                    insert_pos = i+1;
                    break;
                }
            }
        }else{
            for (int i=0; i<4; i++) {
                if((a[i]<= insert_value) &&  (insert_value < a[i+1])){
                    insert_pos = i+1;
                    break;
                }
            }
        }
    }
    //组合最终的数组
    for (int i=0,j=0; i<11; i++) {
        if(i == insert_pos){
            res_arr[i] = insert_value;
        }else{
            res_arr[i] = a[j++];
        }
    }
    //打印数组
    std::cout << "结果数组为：\n";
    for (int i=0; i<11; i++) {
        std::cout << res_arr[i] << "\t";
    }
    std::cout << "\n打印结束\n";
    return 0;
}
