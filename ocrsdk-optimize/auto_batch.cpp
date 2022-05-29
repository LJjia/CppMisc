/**
 * @File: auto_batch
 * @Author: Jialiangjun
 * @Description:自适应batch
 * @Date: Created on 18:41 2022-05-28.
 * @Modify:
 */

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;







/*
 * 划分batch,原则:两个数据之间的差值超过gap,应该归为一簇,一簇之间最大最小值不应该超过2个gap
 */
void rec_autobatch(){
    // 识别模型高都是固定,仅图片宽度不同,因此可以认为是1维的变量


    // 现在最大长度是480
    // 输入已经排序ok
    int max_pic_len=320; //最大宽是多少
    int max_rec_str=32; //最多能识别多少个字符
    int str_num_pre_batch=2; //这个是可以调试的值,认为多少个字符的差距做一个batch比较合适
    // 如果每两个字符一个batch

    // 那么数字之间超过gap的就认为要聚两个类
    int gap=max_pic_len*str_num_pre_batch/max_rec_str;
    cout<<"calc gap "<<gap<<endl;
    // 根据gap计算最大的聚类族数
    int max_batch_num=max_pic_len/gap;

    vector<int> input_data{2,2,4,8,32,34,52,54,69,71,96,122,124,240,250,320,380,400,410,430,450,480,482};
    vector<int> batch_start_idx_array;
    vector<int> num_per_batch_array;
    batch_start_idx_array.reserve(max_batch_num);
    num_per_batch_array.reserve(max_batch_num);

    // 开始计算gap
    int input_size=input_data.size();
    // sort(input_data);

    int start_val=0;
    int start_idx=0;
    // 每个batch中最多64个元素
    const int max_num_per_batch=64;
    for(int proc_idx=0;proc_idx<input_size;){
        batch_start_idx_array.push_back(proc_idx);
        start_val=input_data[proc_idx];
        start_idx=proc_idx;
        proc_idx++;
        while(proc_idx<input_size && input_data[proc_idx]-start_val<=gap && proc_idx-start_idx<max_num_per_batch){
            //batch_len<max_num_per_batch 如果这里是<= 那么最后限制的最大长度将是max_num_per_batch+1
            proc_idx++;
        }
        num_per_batch_array.push_back(proc_idx-start_idx);
    }

    cout<<" output array size "<<batch_start_idx_array.size()<<endl;
    for(auto i :batch_start_idx_array){
        cout<<"idx "<<i<<" val "<<input_data[i]<<endl;
    }
    for(auto i :num_per_batch_array){
        cout<<"num per batch "<<i<<endl;
    }



};


void det_batch(){
    vector<int> row{10,10,10,15,10,50,80,80,120,120,140};
    vector<int> col{10,10,10,15,20,50,80,100,120,120,140};
    // 指定每个batch最多两个数据
    int input_size=row.size();
    const int max_num_per_batch=2;
    // 宽高两个元素相等认为可以组成一个batch
    // 最大每个batch中含有max_num_per_batch个元素
    vector<int> num_per_batch_array;
    num_per_batch_array.reserve(input_size);

    int last_row,last_col;
    int start_idx;
    for(int proc_idx=0;proc_idx<input_size;){
        last_row=row[proc_idx];
        last_col=col[proc_idx];
        start_idx=proc_idx;
        proc_idx++;
        while(proc_idx<input_size && row[proc_idx]==last_row&&col[proc_idx]==last_col&&
                proc_idx-start_idx<max_num_per_batch){
            //cout<<" cacl len "<<proc_idx-start_idx<<"proc "<<proc_idx<<"start "<<start_idx<<endl;
            //batch_len<max_num_per_batch 如果这里是<= 那么最后限制的最大长度将是max_num_per_batch+1
            proc_idx++;
        }
        num_per_batch_array.push_back(proc_idx-start_idx);
    }
    cout<<"array len "<<num_per_batch_array.size()<<endl;
    for(auto i :num_per_batch_array){
        cout<<" num per batch "<<i<<endl;
    }


}
