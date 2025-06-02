
#include <ansi.h>
inherit ROOM;

string show_jiqi();
int do_duoqu(string arg);
mapping data = ([]);
#define BATTLEFIELD_D "/adm/daemons/battlefieldd"
void create()
{
        set("short", HIY "�׻���̨" NOR);
        set("long",@LONG
��վ�ڼ�̨�ϣ��о������쳣���䡣��̨�����Ҳ�������
�в���һ����죨jiqi���������ƺ��Ѿ�Ⱦ������Ѫ��������
�����������ҵĴ򶷣���֪����Ϊ������ʲô���㲻��˼����
ǧ�������鳾�������� ���� ���˾���Ϊ���İ㣿��
LONG);

        set("outdoors", "battlefield");
        set("no_clean_up", 1);
        set("item_desc", ([
                "jiqi"   :  (: show_jiqi :),
        ]));

        setup();
        set_heart_beat(1);
}

void init()
{
        add_action("do_duoqu", "duoqu");
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
                return HIG "���ڻ�û���˶�ȡ���죬�Ͻ���ȡ(duoqu jiqi)�ɡ�\n" NOR;



        str  = HIG "���ڼ����ȡ��������£�\n" NOR;
        str += sprintf(HIC "%-20s%-20s\n" NOR, "����", "����ʱ��");
        str += HIC "-------------------------------\n" NOR;
        key = keys(data);

        for( i=0; i<sizeof(key); i++ )
                str += sprintf("%-20s%-20s\n", key[i], time_period(data[key[i]]));

        str += HIC "-------------------------------\n" NOR;

        if( objectp(ob = query("jiqi_owner")) )
        {
                team_name = ob->query_temp("battle/team_name");
                str += HIC "���ڼ�������" HIY +"��" + team_name + "����" + ob->name() +
                       HIY "(" + ob->query("id") + ")" HIC + "��ȡ�У�\n" NOR;
        }
        else
        {
                str += HIG "���ڼ���û�б���ȡ���Ͻ���ȡ��duoqu jiqi���ɣ�\n" NOR;
        }
        return str;
}

 // ��ȡ����
int do_duoqu(string arg)
{
        object me = this_player();
        object ob;
        string team_name;

        if( !arg || arg != "jiqi" )
                return notify_fail("��Ҫ��ȡʲô��\n");

        if( time() - me->query_temp("last_do_duoqu") < 10 )
                return notify_fail("������ϴζ��쳢��ʱ�䲻��10�룬�����������ԣ�\n");

        // ���˶�ȡʱ���ܶ�ȡ
        if( objectp(ob = query("jiqi_owner")) )
        {
                me->set_temp("last_do_duoqu", time());
                return notify_fail(HIR "��������" + HIY + ob->name() + HIY "(" + ob->query("id") + ")" HIR "��ȡ�У�\n" NOR);
        }

        // ��ȡ
        me->set("jiqi_owner");
        team_name = me->query_temp("battle/team_name");
        if( !undefinedp(data[team_name]) )
        {
                write(HIG "���ȡ�˼��죬��Ķ����ܹ���ȡ����ʱ��Ϊ��" HIY + time_period(data[team_name]) + HIG "��\n" NOR);
                tell_room(this_object(), HIG + me->name() + HIG "��ȡ�˼��죬�����ڶ��顾" + team_name +
                          "���ܹ���ȡ����ʱ��Ϊ��" HIY + time_period(data[team_name]) + HIG "��\n" NOR, ({ me }));
        }
        else
        {
                write(HIG "���ȡ�˼��죬��ʼͳ�Ƽ�ʱ������\n" NOR);
                tell_room(this_object(), HIG + me->name() + HIG "��ȡ�˼��죬�����ڶ��顾" + team_name + "����\n" NOR, ({ me }));
        }
        return 1;
}

void heart_beat()
{
        int time;
        object me;
        string team_name;

        me = query("jiqi_owner");

        if( !objectp(me) )
                return;

        if( !living(me) || environment(me) != this_object() )
        {
                delete("jiqi_owner");
                return;
        }

        BATTLEFIELD_D->add_bonus_score(me, 1);

        team_name = me->query_temp("battle/team_name");

        // �ۼƶ���ʱ��
        if( undefinedp(data[team_name]) )
                data[team_name] = 1;
        else
                data[team_name] += 1;

        time = data[team_name];

        // �ۼƵ�10������ʤ��
        if( time >= 600 )
        {
                BATTLEFIELD_D->win_battle(team_name);
                return;
        }

        if( time >= 540 )
        {
                if( !(time % 10) )
                        CHANNEL_D->channel_broadcast("war", HIR"ս"NOR RED"��"HIR"��"+team_name+HIR"�ܹ���ȡ"+query("short")+"����ʱ��Ϊ��" HIY +time_period(time) + HIR "�������������ʤ��..."NOR);
        }
        return;
}
