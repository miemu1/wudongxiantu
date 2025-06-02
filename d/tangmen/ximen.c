// ximen.c
 

inherit ROOM;
#include <ansi.h>;

string look_gaoshi();
string get_killer();

void create()
{
        set("short", "����");
        set("long",
"�����Ƽ�������ţ�˵�����ţ���ʵ����һ�����ڣ������������и�\n"
"��Ҫ�ܵ���顣������������Ϊ�˰�ȫ�����������һ����λ����������\n"
"��׼Я����������ǽ�����ż���ͨ����ʾ(gaoshi)��һ����ֱ����ʯ���\n"
"�������������졣�������߾������������ˣ����������\n"
);
        set("outdoors", "����");
        set("no_clean_up", 1);
        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
                "east"  : __DIR__"xdajie",
                "northwest"  : __DIR__"ximenroad",
        ]));
        set("objects", ([
                CLASS_D("tangmen") + "/tangrou" : 1,
        ]));
        setup();
}

string look_gaoshi()
{
        return HIR"\n                              ����ͨ����                    \n\n\n"NOR+get_killer() +HIC"\n\n                                               ��������             \n                                               �ƾ���     \n"NOR;
}

string get_killer()
{
        int i;
        string msg;
        object *ob = users();

        msg = "";
        for (i = 0; i < sizeof(ob); i++)
                if ((int)ob[i]->query_condition("killer") && ob[i]->query("family/family_name") == "��������")
                        msg += (ob[i]->short() + "\n");
        if (msg == "")
                return "û��Υ���ߡ�\n";
        else
                return "�������ڼ�������Υ����ӣ�\n\n" + msg;
}

