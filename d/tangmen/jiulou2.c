#include <ansi.h>;
inherit ROOM;
//inherit F_DEALER;

void init();
int do_kan(string arg);

void create()
{
        set("name", "���ž�¥��¥");
        set("short", "���ž�¥��¥");
        set("long",
"�������������ǳ����徲��һ��û������������ģ����Ķ���һЩ��\n"
"�����ˣ��������Ʒ����µġ�����������Ȼ��������ȴ��û������ġ���\n"
"���Ʒ�������һ�ȴ���(window)�ı��ϣ����������ڿ�ʲô������ǽ�Ϲ�\n"
"��һЩ��û�������ֻ���\n"
);
        set("item_desc", ([
                "window" : HIG"һ�ۿ�ȥ,�紺�ĵ�����̣�����ֻ�����Ŀ���������\n"NOR,
        ]));
        set("exits", ([
                "down" : __DIR__"jiulou",
        ]));
        set("objects", ([
                CLASS_D("tangmen") + "/tangfei" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me;
        
        me = this_player();
        
        if ( !arg || arg!= "zihua")
           return notify_fail(HIR"��Ҫ�ҿ�����\n"NOR);
           
        /*if ( count_lt(me->query("combat_exp"), 120000) )   
        {
                tell_object(me,HIR"���жپ����������ǲ��ɵ�����������\n"NOR);
                if ( me->query("qi") < 500 )
                {
                        me->unconcious();
                        return 1;
                }       
                me->add("qi",-500);
                me->add("jingli",-50);
                return 1;
        }*/       
        
        if (me->query_temp("thua"))
           return notify_fail("��Ҫ�ٿ��ˣ������˶��㲻�õģ�\n");
            
        if ( (int)me->query_skill("tangmen-jueqi",1) < 120)
           return notify_fail("��һ���羰����������û�п��������ǲ���������\n");
        
        if (me->query_temp("thua1"))
        {
                me->set_temp("thua2",1);
                me->delete_temp("thua1");
           return notify_fail("һ��ŭ��̰�ĵ��˲����к��³��ģ�\n");   
        }  
        
        message_vision(HIR"�ƻ�"NOR+HIC"��һ����������Ļ����㲻�ɵĳ���...... \n"NOR,me);
        me->set_temp("thua", 1);   
        return 1;
}

