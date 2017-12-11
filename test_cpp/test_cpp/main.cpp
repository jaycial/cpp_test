//
//  main.cpp
//  test_cpp
//
//  Created by 国杰佟 on 2017/12/4.
//  Copyright © 2017年 佟国杰. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <iostream>
int rand_take_five_num_from_ten();
int insert_sort_arr();
int get_volume();
int analysis_num();
int order_string();
int hax_to_dec();
int bin_to_dec();
int vote_system();
int replace_str();
int save_name();
int main(int argc, const char * argv[]) {
    int option = 0;
    std::cout << "请选择功能:\n";
    std::cout << "1:抽签题:\n";
    std::cout << "2:插入排序:\n";
    std::cout << "3:数学公式类计算题\n";
    std::cout << "4:分解与解析\n";
    std::cout << "5:字符串处理\n";
    std::cout << "6:十六进制转十进制\n";
    std::cout << "7:二进制转十进制\n";
    std::cout << "8:投票系统\n";
    std::cout << "9:替换字符串\n";
    std::cout << "10:保存人名到本地文件\n";
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
            case 3:
                get_volume();
                break;
            case 4:
                analysis_num();
                break;
            case 5:
                order_string();
                break;
            case 6:
                hax_to_dec();
                break;
            case 7:
                bin_to_dec();
                break;
            case 8:
                vote_system();
                break;
            case 9:
                replace_str();
                break;
            case 10:
                save_name();
                break;
            default:
                break;
        }
        std::cout << "请选择功能:\n";
        std::cout << "1:抽签题:\n";
        std::cout << "2:插入排序:\n";
        std::cout << "3:数学公式类计算题\n";
        std::cout << "4:分解与解析\n";
        std::cout << "5:字符串处理\n";
        std::cout << "6:十六进制转十进制\n";
        std::cout << "7:二进制转十进制\n";
        std::cout << "8:投票系统\n";
        std::cout << "9:替换字符串\n";
        std::cout << "10:保存人名到本地文件\n";
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
//已经圆柱体的底半径r，高h，求体积v。公式给出:  v = pi * r^2 * h
int get_volume(){
    double pi = 3.14;
    double r,h,v;
    std::cout << "计算圆柱体积，请输入\n半径r=";
    std::cin >> r;
    std::cout << "\n高h=";
    std::cin >> h;
    //计算
    v = pi*pow(r, 2)*h;
    std::cout << "经过计算，体积v=" << v <<std::endl;
    return 0;
}

//给定一个长度为4的10进制整数，将各个数字分解到数组里。例如，给定1345，保存到数组int buf[4]里，则buf的内容依次是1,3,4,5
int analysis_num(){
    int num = 0;
    int buf[4];
    int base = 1000;
    bool check_flag = false;
    //接受输入，确保用户输入的是一个四位数
    while (!check_flag) {
        std::cout << "请输入一个四位数num=";
        std::cin >> num;
        check_flag = (num/1000 > 0 && num/10000<=0);
        if(!check_flag){
            std::cout << "输入有误！\n";
        }
    }
    for (int i=0; i<4; i++) {
        base = (base/(pow(10, i)));
        buf[i] = (num - num%base)/base;
        num = num%base;
        base = 1000;
    }
    //打印
    for (int i=0; i<4; i++) {
        std::cout << "第" << i+1 << "位:" << buf[i] << "\t" ;
    }
    std::cout << "\n打印结束\n";
    return 0;
}

//输入4个字符串，将其保存，排序后输出。例如，输入dad, baby, kitty, buy , 输出 baby  buy   dad  kitty
int order_string(){
    std::string s[4];
    std::string tmp;
    int res;
    std::cout << "输入四个字符串\n";
    for (int i=0; i<4; i++) {
        std::cout << "第" << i+1 << "个:";
        std::cin >> s[i];
        std::cout << "\n";
    }
    //比较大小(类似冒泡)
    for (int i=0; i<4; i++) {
        for (int j=i+1; j<4; j++) {
            res = s[i].compare(s[j]);
            if(res > 0){
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
    //打印结果
    std::cout << "打印结果为:\n";
    for (int i=0; i<4; i++) {
        
        std::cout << s[i] << "\n";
    }
    std::cout << "打印结束\n";
    return 0;
}

//输入16进制的字符串，转换为整数输出。例如，输入字符串 "A12B"，函数返回整数41259。
int hax_to_dec(){
    std::string s;
    int result = 0;
    unsigned long length = 0;
    int current_num;
    int tmp;
    //输入
    std::cout << "请输入一个十六进制数：";
    std::cin >> s;
    //取长度
    length = s.length();
    //for循环计算
    for (int i=0; i<s.length(); i++) {
        current_num = s.at(i);
        if(current_num > 47 && current_num < 58){
            current_num -= 48;
        }else if(current_num > 64 && current_num < 71){
            current_num -= 55;
        }else{
            current_num -= 87;
        }
        tmp = pow(16, (length - i -1));
        result += current_num*tmp;
    }
    std::cout << "打印结果为：" << result << std::endl;
    return 0;
}

//将2进制字符串转换为整数输出。函数原型 例如，输入字符串"11000000111001"，函数返回整数12345.
int bin_to_dec(){
    std::string s;
    int result = 0;
    unsigned long length = 0;
    int current_num;
    std::cout << "请出入一个二进制的数字：";
    std::cin >> s;
    //取长度
    length = s.length();
    //for循环
    for (int i=0; i<length; i++) {
        current_num = s.at(i);
        if(49 == current_num){
            result += pow(2, length-i-1);
        }
    }
    std::cout << "打印结果" << result << std::endl;
    return 0;
}
int vote_system(){
    bool vote_status = false;
    int res_num = 0;
    for (int i=0; i<3; i++) {
        std::cout << "请输入第" << i+1 << "位裁判的投票(0反对，1赞成):";
        std::cin >> vote_status;
        if(vote_status){
            res_num ++;
        }
        
    }
    //打印结果
    if(res_num >=2){
        std::cout << "通过\n";
    }else{
        std::cout << "未通过\n";
    }
    return 0;
}
//将日期字符串中的"-"转换成"/"，如将"2015-03-18"转换为"2015/3/18"
int replace_str(){
    std::string s;
    std::cout << "请输入日期：";
    std::cin >> s;
    //for循环替换'-'为'/'
    for (int i=0; i<s.length(); i++) {
        if(s.at(i) == 45){
            s.replace(i, 1, "/");
        }
    }
    //打印结果
    std::cout << "打印结果为：" << s << std::endl;
    return 0;
}

int save_name(){
    std::fstream file;
    std::string ch;
    file.open("name.txt",std::ios::out);
    std::cout << "请输入姓名：";
    std::cin >> ch;
    while (ch != "0") {
        file << ch << "\n";
        std::cout << "请继续输入姓名(输入0结束)：";
        std::cin >> ch;
    }
    file.close();
    return 0;
}
