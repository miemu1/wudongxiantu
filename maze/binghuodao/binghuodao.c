inherit DEMONROOM;

#include <ansi.h>

void setup()
{

        set("no_rideto", 1);         // ���ò������������ط�
        set("no_flyto", 1);          // ���ò��ܴ������ط�����������
        set("binghuo", 1);           // ��ʾ�ڱ���
        set("no_die", 1);
        set("outdoors", "battle4");

        ::setup();
}

void init ()
{
        if (! userp(this_player()))return;
        
        if (! wizardp(this_player()))
        {
                this_player()->start_busy(1+ random(2));
                tell_object(this_player(), NOR + WHT "���������ͻȻ����ʧ�˷���\n" NOR);
        }
        
        // �ǰ�ս�ڼ䣬�������з����µ�һ��ĳ�Ա
        if( !BUNCH_D->is_battle_start() && !BUNCH_D->is_top_bunch(this_player()) )
        {
                this_player()->move(__DIR__"haitan");
        }
        // ��ս�ڼ䣬�Ͻ����µ�һ���Ա���ܽ���
        if( (BUNCH_D->is_battle_start() || BUNCH_D->is_battle_open()) && BUNCH_D->query_bunch_topten(1) == query("bunch/bunch_name", this_player()) )
        {
                this_player()->move(__DIR__"haitan");
        }
}
