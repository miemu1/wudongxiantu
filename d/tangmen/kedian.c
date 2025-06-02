#include <ansi.h>;
#include "/d/tangmen/npc/job1.h";

void create()
{
        set("short", "�͵�");
        set("long",
"�������������Ŀ�ջ������ǳ���¡������οͶ�ѡ��������ţ���\n"
"�ŵ��ӿ������ɵĽ�����˯��Ҳ����ѵġ���С����������æ������ת��\n"
"�Ӵ���������ĺ������ѡ��͵�����˴Ӳ�¶�棬��������˭���и��ָ�\n"
"���Ĳ²⡣�����е��������������˶�֪���ģ���������ŵĵ��̣��ݲ�\n"
"���������ڴ˺�����Ϊ��\n"
);
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room", 1);
        set("item_desc", ([
                "paizi" : "��\n",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"bdajie1",
                "up"   : __DIR__"kedian2",
        ]));

        setup();
        
}

int valid_leave(object me, string dir)
{          
        object ob;
        mapping myfam;
        ob = this_player();

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס�����������"+HIC"��������"NOR+"��\n");

        if ( me->query_temp("rent_paid") && dir == "west" )
        {     
                myfam = (mapping)ob->query("family");
                if (myfam["family_name"] != "��������")
                        return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ����˻���ΪС���ź����أ�\n");
                ob->delete_temp("rent_paid");
                ob->move("/d/tangmen/bdajie1");
                tell_object(ob,"��С��Ц�����˵������λ"+RANK_D->query_respect(ob)+"����ӭ����"+HIG"���ſ͵�"NOR+"\n\n");
                return 1;
        }
        return ::valid_leave(me, dir);
}


