//chaifang.c		�Ĵ����š���

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��");
	set("long",
"�����Ǻ�Ժ�Ĳ񷿣����ж��������õĲ�����ݶ���ľ�ĵ���ζ��\n"
"��ɽҲ�ƵĲ����һ��С��ͨ���ɽ����˵�����û�Ų��ǻ����������\n"
"Ы�����򲻹��߿ɲ�Ҫ����ѽ�����߾��ǳ����ˣ�\n"
);
	set("exits", ([
                "northeast" : __DIR__"houzhai",
	        "west" : __DIR__"chufang",
		"south" : __DIR__"nzlange1",
	        "north" : __DIR__"exiaolu1",
	]));
        create_door("northeast","ľ��","southwest",DOOR_CLOSED);
	set("objects", ([
                CLASS_D("tangmen") + "/tangpeng" : 1,
	]));
	set("area", "����");
	setup();
}
int valid_leave(object me, string dir)
{
        if ( (dir == "north") && ( (string)me->query("family/family_name") != "��������") && 
                !wizardp(me) && (objectp( present("tang peng", environment(me)) ) ))
                return notify_fail("����һ���֣�˵�������㲻���������ˣ���������ǰ���ˣ���\n");
        else
                return ::valid_leave(me, dir);
}

