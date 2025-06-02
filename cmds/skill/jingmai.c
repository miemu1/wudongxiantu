// This program is a part of NT MudLIB

#include <ansi.h>

#define ZHOUTIAN_D      "/adm/daemons/zhoutiand"

inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
        string *xs;
        string msg;
        int i;

        if( me->is_busy() || me->is_fighting() )
                return notify_fail(BUSY_MESSAGE);

        if( !arg || arg == "" ) {
                msg  = HIC "��������Ѩ״̬\n" NOR;
                msg += HIC "��" HIY "����������������������������������������������" HIC "��\n" NOR;
                msg += HIC "\t\tС���쾭��\n" NOR;
                msg += HIC "��" HIY "����������������������������������������������" HIC "��\n" NOR;
                msg+=HIG"������\t\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"������\t\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��ά��\t\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��ά��/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��ά��\t\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��ά��/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"����\t\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/����/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"����\t\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/����/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"������\t\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"������\t\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg += HIC "��" HIY "����������������������������������������������" HIC "��\n" NOR;
                msg += HIY "\t\t�����쾭��\n" NOR;
                msg += HIC "��" HIY "����������������������������������������������" HIC "��\n" NOR;
                msg+=HIG"��̫����\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��̫����/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��̫����\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��̫����/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��̫����\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��̫����/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��̫����\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��̫����/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg+=HIG"��������\t\t\t\t"+((query("jingmai/finish", me) || query("jingmai/��������/chongxue_ok", me))?HIM"�Ѵ�ͨ":HIR"δ��ͨ")+"\n"NOR;
                msg += HIC "��" HIY "����������������������������������������������" HIC "��\n" NOR;
                write(msg);
                help(me);

                if( query("jingmai/finish", me) || query("jingmai/������/chongxue_ok", me) )
                        MYGIFT_D->check_mygift(me, "newbie_mygift/yinqiaomai");

                return 1;
        }

        if( arg == "all" || arg == "bh" || arg == "bh2" )
        {
                me->start_more(ZHOUTIAN_D->show_bianhao(arg));
                return 1;
        }

        ZHOUTIAN_D->show_jingmai(me, arg);

        return 1;
}

int help(object me)
{
        write(@HELP
�鿴ָ��������ѧ���ʹ��ָ�� jingmai <������> ��ѯ��
�鿴С����ͭ�˱������ jingmai bh ��ѯ��
�鿴������ͭ�˱������ jingmai bh2 ��ѯ��
�鿴��С����ͭ�˱������ jingmai all ��ѯ��
����ϸ�Ĳο��ļ���ͨ�������ļ� help zhoutian �鿴��

HELP
);
        return 1;
}
