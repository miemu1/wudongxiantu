// Room: /tangmen/ndajie1.c

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
        set("long",
"������Ƽ�����ϴ���ˣ�������ͷ���졣���߾��ǻش��õķֵ�\n"
"�ˣ�ƽ����һЩ������ҩ�������Լ��ǲ���ҩ����Ϊ���ϴ������ġ�ֻ��\n"
"�Լ����á�������ȥ�ľ���һЩ�ˣ�����ǴҴҶ���������ææ��ȥ����\n"
"ʲô�ط��أ��Լ�һ��ȥ��֪���ˡ�\n"
);
        set("outdoors", "����");
        set("no_clean_up", 0);
        set("exits", ([ 
                "west"  : __DIR__"hcfdian",
                "north" : __DIR__"zhongxin",
                "east"  : __DIR__"tmbingqi",
        ]));

        setup();
        replace_program(ROOM);
}

