//lianyunge.c		�Ĵ����š����Ƹ�

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���Ƹ�");
	set("long",
"���������Ƹ�������һ�������������Ľ�����������ʮ��������\n"
"ÿ�������϶����������ĵ������롢���Ϭ�����ѵ���ʮ���ֲ�ͬ����\n"
"�����ޡ��컨��������˸��پ�����ġ��ơ��֣�������̾���ǵذ��Ͼ�\n"
"Ҳʮ�ֱ���Ŀ��������ʥ���칬����������������̫���Ͼ�������շ�\n"
"�ڵ�¯�ﰾ���ĵ��ֹ������ƾ�����Ʒ�����Ǹ����˾�����ǣ��ذ岢\n"
"����Ϊ��Щ��̶���˿����͹��ƽ��������ʮ��ƽ���������ڼ����һ�㣡\n"
);
	set("exits", ([	
			"east"  : __DIR__"eting",
			"west"  : __DIR__"wting",
			"north" : __DIR__"nzlang1",
			"south" : __DIR__"shuige2",]));
        set("objects", ([
                CLASS_D("tangmen") + "/tangtian" : 1,
        ]));
//	set("length",20);
	set("valid_startroom",1);
	set("area", "����");
	setup();
	replace_program(ROOM);
}
