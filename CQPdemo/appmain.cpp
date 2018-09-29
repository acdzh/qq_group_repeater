/*/
/*  main.cpp(Vesion 1.0.0)
/*  人类的本质机器人
/*
/*  Created by acdzh on 2018/09/29.
/*  Copyright © 2018年 acdzh. All rights reserved.
/*/
#include "stdafx.h"
#include "string"
#include "cqp.h"
#include "appmain.h" //应用AppID等信息，请正确填写
#include <vector>

using namespace std;

int ac = -1; //AuthCode 
bool enabled = false;



vector<string> msgs = {"qqqqwwwwqqqq", "wwwwqqqqwwww"};
unsigned int countn = 0;


void reply(string &msg, int64_t groupid) {
	countn++;
	msgs[countn % 2] = msg;
	if (msgs[0] == msgs[1]) {
		CQ_sendGroupMsg(ac, groupid, msg.c_str());
	}
}


CQEVENT(const char*, AppInfo, 0)() {
	return CQAPPINFO;
}
CQEVENT(int32_t, Initialize, 4)(int32_t AuthCode) {
	ac = AuthCode;
	return 0;
}
CQEVENT(int32_t, __eventGroupMsg, 36)(int32_t subType, int32_t msgId, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font) {
	string s(msg);
	reply(s, fromGroup);
	return EVENT_IGNORE; //关于返回值说明, 见“_eventPrivateMsg”函数
}
CQEVENT(int32_t, __menuA, 0)() {
	MessageBoxA(NULL, "https://github.com/acdzh", "" ,0);
	return 0;
}

