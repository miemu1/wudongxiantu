// jiulou.c

#include "/d/tangmen/npc/job1.h";

void create()
{
        set("short", "���ž�¥");
        set("long",
"�����Ƽ��������ľ�¥����˵�����˲�֪�����˲����������˵��ˣ�\n"
"��Ҫ�����һ���ݣ������顣��˵���˵�����ĳЩ�����кô�������\n"
"û��ȷ���ǲ��ǵģ���Ϊ������˶���Ц�����𡣵��������һ�԰���¥\n"
"�²��ü��ף�¥�����������ϰ�������氡����֪��û�и�������������\n"
"��������˵������ʲô�ô�����\n"
);
        set("exits", ([
                "south" : __DIR__"xdajie",
                "up"    : __DIR__"jiulou2",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
        ]));
        set("no_fight", 1);
        set("resource/water", 1);
        set("no_steal", 1);
        setup();
}

