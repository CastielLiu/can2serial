#include"can2serial/can2serial.h"
#include<ros/ros.h>

int main()
{

	Can2serial can2serial;                     //实例化 can2serial
	can2serial.configure_port("/dev/host_pc"); //配置串口
	can2serial.StartReading();                 //开始读取数据，包括can数据以及can分析仪应答数据
	CanMsg_t can_msg;
	
	usleep(100000);
	can2serial.clearCanFilter();               //清除can滤波器

	can2serial.configBaudrate(250);            //配置can通讯波特率
	
	//can2serial.setCanFilter_alone(0x01,0x4E0);
	//can2serial.setCanFilter(0x02,0x4E0,0x7ff); //500-53f
	//can2serial.setCanFilter(0x03,0x500,0x7c0);
	
	//can2serial.inquireFilter(2);
	//can2serial.inquireFilter(3);
	//can2serial.setCanFilter(0x01,0x123,0x7ff);
	
	
	while(1)
	{
		//usleep(1000);
		if(!can2serial.getCanMsg(can_msg))
			continue;
		ROS_INFO("ID:%x",can_msg.ID);
		//can2serial.sendCanMsg(can_msg);
	}
	
	return 0;
}
