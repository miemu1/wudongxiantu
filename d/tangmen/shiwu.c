//shiwu.c		�Ĵ����š�ʯ��

inherit ROOM;

void create()
{
	set("short", "ʯ��");
        set("long",
"����һ���ô����ɵ�С��,һ����,���ŵ�һ��Ũ�ҵĻ��㣬���й�\n"
"��һ����Ůͼ,���������廨����,������һ����,��������һ��ĵ���Ľ�\n"
"������.�ѵ�����˭�ҹ���Ĺ뷿��\n"
);
        set("exits", ([
                "north" :__DIR__"huayuan",   
           ]));
        set("objects", ([
                CLASS_D("tangmen") + "/tanglyz" : 1,
         ]));
        setup();
        replace_program(ROOM);
}
