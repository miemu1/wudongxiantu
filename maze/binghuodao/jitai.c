inherit ROOM;

#include <ansi.h>

int TEST_FLAG = 0;

public void set_test_flag(int n){TEST_FLAG = n;}

string show_jiqi();
int do_duoqu(string arg);
mapping data = ([]);

void create()
{
        set("short", HIY "��̨" NOR);
        set("long",@LONG
��վ�ڼ�̨�ϣ��о������쳣���䡣��̨�����Ҳ�������
�в���һ����죨jiqi���������ƺ��Ѿ�Ⱦ������Ѫ��������
�����������ҵĴ򶷣���֪����Ϊ������ʲô���㲻��˼����
ǧ�������鳾�������� ���� ���˾���Ϊ���İ㣿��
LONG);

        set("no_rideto", 1);         // ���ò������������ط�
        set("no_flyto", 1);          // ���ò��ܴ������ط�����������
        set("binghuo", 1);           // ��ʾ�ڱ���
        
        set("no_die", 1);

        set("no_clean_up", 1);

        set("exits", ([ 
                "down"     : __DIR__"jitaiqian",
        ]));
        
        set("item_desc", ([ 
                "jiqi"   :  (: show_jiqi :),
        ]));

        setup();

        set_heart_beat(1);
}

string show_jiqi()
{
        int i;
        string *key;
        string  str;
        object  me = this_player();
        object  ob;
        string  team_name;
        
        if( !sizeof(data) )
                return HIG "���ڻ�û�а��ɶ�ȡ���죬�Ͻ���ȡ(duoqu jiqi)�ɡ�\n" NOR;

        str = HIG "���ڼ����ȡ��������£�\n" NOR;
        str += sprintf(HIC "%-20s%-20s\n" NOR, "����", "����ʱ��");
        str += HIC "-------------------------------\n" NOR;
        key = keys(data);
        
        for (i = 0; i < sizeof(key); i ++)
                str += sprintf("%-20s%-20s\n", key[i], time_period(data[key[i]]));

        str += HIC "-------------------------------\n" NOR;
        if( objectp(ob = query("jiqi_owner")) )
        {
                team_name = query("bunch/bunch_name", ob);
                str += HIC "���ڼ�������" HIY +"��" + team_name + "����" + ob->name() +
                       HIY "(" + query("id", ob) + ")" HIC + "��ȡ�У�\n" NOR;
        }
        else
        {
                str += HIG "���ڼ���û�б���ȡ���Ͻ���ȡ��duoqu jiqi���ɣ�\n" NOR;
        }
        return str;
}

void init()
{
        add_action("do_duoqu", "duoqu");
}

// ��ȡ����
int do_duoqu(string arg)
{
        object me = this_player();
        object ob;
        string team_name;

        if( !arg || arg != "jiqi" )
                return notify_fail("��Ҫ��ȡʲô��\n");

        if( time() - query_temp("last_do_duoqu", me) < 10 )
                return notify_fail("������ϴζ��쳢��ʱ�䲻��10�룬�����������ԣ�\n");

        // ���˶�ȡʱ���ܶ�ȡ
        if( objectp(ob = query("jiqi_owner")) )
        {
                me->set_temp("last_do_duoqu", time());
                return notify_fail(HIR "��������" + HIY + ob->name() + HIY "(" + query("id", ob) + ")" HIR "��ȡ�У�\n" NOR);
        }
        
        // �ް�����ʿ���ܶ�ȡ
        if( !query("bunch/bunch_name", me) )
        {
                me->move("/d/city/wumiao");
                tell_object(me, "�㻹���ȼӸ����ɰɣ�\n");
                return 1;
        }

        // �ǰ�ս�ڼ䲻�ܶ�ȡ
        if (! BUNCH_D->is_battle_start() && ! TEST_FLAG)
                return notify_fail("���ڲ����ڰ�ս�ڼ䣬���ȡ�����ʲô��\n");
        
        // ��ȡ
        set("jiqi_owner", me);
        team_name = query("bunch/bunch_name", me);
        if( !undefinedp(data[team_name]) )
        {
                write(HIG "���ȡ�˼��죬��Ķ����ܹ���ȡ����ʱ��Ϊ��" HIY + time_period(data[team_name]) + HIG "��\n" NOR);
                tell_room(this_object(), HIG + me->name() + HIG "��ȡ�˼��죬�����ڰ��ɡ�" + team_name +
                          "���ܹ���ȡ����ʱ��Ϊ��" HIY + time_period(data[team_name]) + HIG "��\n" NOR, ({ me }));
        }
        else
        {
                write(HIG "���ȡ�˼��죬��ʼͳ�Ƽ�ʱ������\n" NOR);
                tell_room(this_object(), HIG + me->name() + HIG "��ȡ�˼��죬�����ڰ��ɡ�" + team_name + "����\n" NOR, ({ me }));
        }
        
        // CHANNEL_Dͨ��
        CHANNEL_D->channel_broadcast("war",HIG+me->name()+HIG"�ɹ���ȡ���죬�����ڰ��ɡ�"+query("bunch/bunch_name", me)+
                                     "����ʱȡ�ü������Ȩ��\n" NOR);

        return 1;
}

void heart_beat()
{               
        int time;
        object me;
        string team_name;

        me = query("jiqi_owner");

        reset_eval_cost();
        
        // �ǰ�ս�ڼ䣬���֮ǰ�ļ�¼
        if( !BUNCH_D->is_battle_start() && !TEST_FLAG )
        {
                if (query("jiqi_owner"))delete("jiqi_owner");
                if (sizeof(data)) data = ([]);
                return;
        }

        if( !objectp(me) ) return;
        
        if( !living(me) || environment(me) != this_object() )
        {
                delete("jiqi_owner");
                return;
        }
        
        BUNCH_D->add_bonus_score(me, 1);  // ��߸��˰��ɹ��׶�
        
        // �ް���
        team_name=query("bunch/bunch_name", me);
        if (! team_name)return;

        // �ۼƶ���ʱ��
        if( undefinedp(data[team_name]) )
                data[team_name] = 1;
        else
                data[team_name] += 1;

        time = data[team_name];
        
        if( time >= 600 )
        {
                BUNCH_D->win_battle(me, team_name);
                return;
        }

        if( time >= 540 )
        {
                if( !(time % 10) )
                        CHANNEL_D->channel_broadcast("war", HIR"���ɡ�"+team_name+HIR"���ܹ���ȡ"+query("short")+"����ʱ��Ϊ��" HIY +time_period(time) + HIR "�������������ʤ��..."NOR);
        }
        return;
}       
