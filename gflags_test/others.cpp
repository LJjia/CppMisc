/**
 * @File: others
 * @Author: Jialiangjun
 * @Description:
 * @Date: Created on 17:01 2022-05-14.
 * @Modify:
 */

#include <iostream>
#include <string>
#include <gflags/gflags.h>

DECLARE_string(your_name);

void OtherFunc(){
    std::cout<<"other file call name "<<FLAGS_your_name<<std::endl;
}
