// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "������");
	set("long", @LONG
�����������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ�
�Ͼ���������ݡ��Ա��ƺ���һ�����š�
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_learn", "1");
	set("no_study", "1");
	set("no_learn", "1");
	set("no_dazuo", "1");
	set("no_sleep_room", "1");

	set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("action_list", ([
		"ÿ������" : "day_sign",
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
		"north"   : __DIR__"wumiao2",
		"upnorthwest": "/d/wizard/guest_room",
		"south": "/d/fuben/ciyuan",
	]));
	create_door("northwest", "����", "southeast", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("mrrw","day_sign");
}

int valid_leave(object me, string dir)
{
      if (dir=="northwest"&& me->query("id")=="xiguazi" )
		return notify_fail("����Ϊ�������¹������ȥ�˵ء�\n");		
		
	if (dir == "northwest" && ! userp(me) && ! me->is_chatter())
		return 0;
	return ::valid_leave(me, dir);
}

int mrrw(string arg)
{
	object me=this_player();
	string type;
	string msg="", line="";
if (!arg) {
		msg = ZJOBLONG+
		      "Ŀǰ��Ϸ�е��ճ���������[������]��\n";
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "���ѵ��["+me->query("fuben/wuguan/mun")+"/3]:day_sign wuguan";
		msg += ZJSEP"�������["+me->query("fuben/jinbing/mun")+"/3]:day_sign jinbing";		
	}
	else if(arg=="wuguan"){
	msg = ZJOBLONG+"�������[���ѵ��]��"ZJBR
	                  "��������������������������������"ZJBR
                      "����ר������"ZJBR
                      "���뽭�������������ѣ����������ѧ�ճ�ʼ�ĺõط�������֮·�����ѧ�տ�ʼ��\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "����ǰ��:day_sign wuguan2";	
	}
	else if(arg=="wuguan2"){ 
	me->move("d/city/wuguan/qianting");	
	}
	else if(arg=="jinbing"){
	msg = ZJOBLONG+"������Զ��[�������]��"ZJBR
	                  "��������������������������������"ZJBR
                      "���һֱ������ԭ���Ĳ�������������̽������ڴ�̽���飬�����̽�ɻ�÷������\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "����ǰ��:day_sign jinbing2";	
	}
	else if(arg=="jinbing2"){ 
	me->move("d/guanwai/ningyuan");	
	}	
	write(msg + "\n");			
	return 1;
}