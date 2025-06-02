inherit ROOM;

#include <ansi.h>

int TEST_FLAG = 1;

public void set_test_flag(int n){TEST_FLAG = n;}

void create()
{
        set("short", HIR "��̳" NOR);
        set("long",
"�����Ǳ��𵺵����ģ�Ҳ��һ����̳�������̳û�����֣���\n"
"���佨��ĸ��ӶȺ���������������������ɽ�ķ���̨����̳����\n"
"����ȼ����ɫ�Ļ��棬���аڷ���һ���޴����¯�ͼ�̨(jitai)��\n"
);

        set("no_rideto", 1);         // ���ò������������ط�
        set("no_flyto", 1);          // ���ò��ܴ������ط�����������
        set("binghuo", 1);           // ��ʾ�ڱ���

        set("no_clean_up", 1);
        
        set("outdoors", "battle4");
       
        set("league_flag", "ALL_LEAGUE"); // Ĭ�����а��ɶ�������ǰ�����ܵ�
        set("exits", ([ 
                "north"   : __DIR__"xuanwutai",
                "south"   : __DIR__"shenghuotai",
        ]));
        
        set("item_desc", ([ 
                "jitai"   :  HIC "��̨�Ծ�������һ����ֵ�������ת��(turn)������lahuan�����ܻῪ��ʲô���ء�\n" NOR,
                "lahuan"  :  HIM "һ����Բ�ε���������ͭɫ���ƺ�������ʲô���ء�\n" NOR,
        ]));

        setup();
}

void init()
{
        add_action("do_turn", "turn");
}

int do_turn(string arg)
{
        object me = this_player();
        object ob;
        
        if (! arg || arg != "lahuan")
                return notify_fail("��Ҫת��ʲô������\n");
                
        if( query("exits/enter") )
                return notify_fail("�ܵ�����Ѿ������ˣ���û�°ɣ�������\n");

        // ��ȡ��ս�����ļ����ж��Ƿ��ܵ������ˣ���������������
        if( !BUNCH_D->is_battle_start() && !TEST_FLAG )
                return notify_fail("��ʹ��ת���������ƺ�û��ʲô���á�\n");
                
        // ��ëʨ���������ܿ���
        if (objectp(ob = present("jinmao shiwang", this_object())))
        {
                message_vision(HIM "һ���â������" + ob->name() + HIM "����$N" HIM "��ǰ���ȵ������ߣ��ȹ����������˵����\n" NOR, me);
                return 1;
        }

        write("��ʹ��ת��������ֻ��һ�����죬��̳΢΢��������̳��¶��һ��ͨ��(enter)��\n" NOR);
        tell_room(this_object(), HIC + me->name() + HIC "ʹ��ת��������ֻ��һ�����죬��̳΢΢��������̳��¶��һ��ͨ��(enter)��\n" NOR, ({me}));

        set("exits/enter", __DIR__"st0");
        
        remove_call_out("close_out");   
        call_out("close_out", 300);
        
        me->start_busy(2);
        
        return 1;
}

void close_out()
{
        delete("exits/enter");  
        tell_room(this_object(), HIC "һ�����죬��̳΢΢�������ƺ����ܵ��ر��ˡ�\n" NOR, ({}));
}


// �������� ��ëʨ�������� ,league��������������Ϊ"ALL_LEAGUE"��ʾ�κΰ��ɶ����Խ���
public set_flag(string league)
{
        set("league_flag", league);
        remove_call_out("clear_league_flag");
        call_out("clear_league_flag", 60, league);
        
        if (league != "ALL_LEAGUE")
                tell_room(this_object(), HIM "����ֻ�С�" + league + HIM "��������ǰһ���ӽ����ܵ���\n" NOR, ({}));
}
void clear_league_flag(string league)
{
        set("league_flag", "ALL_LEAGUE");
        
        if (league != "ALL_LEAGUE")     
                tell_room(this_object(), HIG "�������ɿ��Խ����ܵ��ˣ�\n" NOR, ({}));
}

int valid_leave(object me, string dir)
{
        
        if (dir == "enter")
        {
                // �ǰ�ս���ܽ���
                if( !BUNCH_D->is_battle_start() && !TEST_FLAG )
                        return notify_fail("���ڲ��ǰ�ս�ڼ䣬���ܽ����ܵ���\n");
                
                // ��ëʨ��δ�����ı�־���ܽ���
                if (present("xie xun", this_object()))
                        return notify_fail("��ëʨ���ػ��ż�̳�ܵ������ܽ��룡\n" NOR);
                
                // ���а������ȱ�־����־����ALL_LEAGUE���Ҳ��Ǳ�־ָʾ���ɣ����־����ʱ���ܽ���
                if( query("league_flag") != "ALL_LEAGUE" && query("bunch/bunch_name", me) != query("league_flag") && !TEST_FLAG )
                        return notify_fail("��������ʱ���ܽ��룬������΢�ȵȰɣ�\n");
        }
        
        return ::valid_leave(me, dir);
}
