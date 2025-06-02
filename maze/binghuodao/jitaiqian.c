inherit ROOM;

#include <ansi.h>

int TEST_FLAG = 0;

public void set_test_flag(int n){TEST_FLAG = n;}

void create()
{
        set("short", HIY "��̨ǰ" NOR);
        set("long",@LONG
����һ�������Ķ�Ѩ���������ʡ���Ѩ���ܲ����˸�����
�ģ�ʯ����Ҳ���и��ּ�������ڣ������ѻ�Ϊ�׹ǡ���Ѩ��
�аڷ���һ����ʯ���ɵļ�̨��jitai���� �������һ���ʺ�
�����ġ�
LONG);

        set("no_rideto", 1);         // ���ò������������ط�
        set("no_flyto", 1);          // ���ò��ܴ������ط�����������
        set("binghuo", 1);           // ��ʾ�ڱ���


        set("no_clean_up", 1);
        
        set("exits", ([ 
                "out"     : __DIR__"jitan",
        ]));
        
        set("item_desc", ([ 
                "jitai"   :  HIC "����һ�������ļ�̨���ƺ����й����ͼ��룬�ƺ���������(jump jitai)��̨��\n" NOR,
        ]));

        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();
        
        if (! arg || arg != "jitai")
                return notify_fail("��Ҫ����������\n");
                
        // ��������򱣻��Ĳ����Ӱ���ʱ��
        if( query_temp("apply/invisible", me) )
        {
                tell_object(me, HIG "�㴦������״̬�������ϼ�̨��\n" NOR);
                return 1;
        }
        if (me->query_condition("die_guard"))
        {
                tell_object(me, HIG "�㴦�ڱ�����״̬�������ϼ�̨��\n" NOR);
                return 1;
        }
        
        if( query("age", me) < 5 && query("reborn/times", me) )
        {
                tell_object(me, HIG "�㴦�ڱ�����״̬�������ϼ�̨��\n" NOR);
                return 1;
        }

        message_vision(HIC "$N����һԾ�����ϼ�̨��\n" NOR, me);

        me->move(__DIR__"jitai");
        
        return 1;
}
