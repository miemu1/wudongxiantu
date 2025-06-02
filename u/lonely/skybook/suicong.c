cat suicong.c
// ���ϵͳ

#include <ansi.h>
inherit F_CLEAN_UP;

#define SUICONG_D    "/adm/daemons/suicongd"

int help(object me);

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{

        string arg1, arg2, arg3;
        if (! arg)return help(me);
        
        
        if (! find_object(SUICONG_D))load_object(SUICONG_D);
        
        // ��ʾ���п��Ի������б�
        if (arg == "list")
        {
                return SUICONG_D->show_suicong(me);             
        }
        
        // �鿴ָ�����
        if (sscanf(arg, "cha %s", arg1) == 1)
        {
                return SUICONG_D->show_suicong_target(me, arg1);
        }
        // �鿴ָ����ҵ�ָ�����
        if (sscanf(arg, "chaplayer %s %s", arg1, arg2) == 2)
        {
                object ob = find_player(arg1);
                if (! ob)return notify_fail("��Ҳ����ڣ�\n");
                                
                return SUICONG_D->show_suicong_target(ob, arg2);
        }
        // �ٻ����     
        if (sscanf(arg, "sum %s", arg1) == 1)
        {
                return SUICONG_D->summon_suicong(me, arg1);
        }
        // �������
        if (arg == "hide")
        {
                return SUICONG_D->hide_suicong(me, arg1);
        }
        // ���Կ����ڼ�ʹ�ã���ҿ���ȡ2���������
        if (arg == "tiyan")
        {
                SUICONG_D->give_suicong(me, "������ƽһָ");

                write(HIG "��ȡ�ˡ�������ƽһָ������ʹ�� suicong sum ������ƽһָ �ٻ���\n" NOR);
                return 1;
        }
}

int help(object me)
{
        string sMsg;
        
        write(@TEXT              
        
=--------------------------------------------------------------------------------------=
        ���ϵͳ����ָ��  >>

        suicong                   �鿴ָ��˵���͵�ǰ�ٻ��������
        suicong list              �鿴�����Ѿ����ŵ����
        suicong cha �����        �鿴ָ����ӵ���ϸ��Ϣ
        suicong sum �����        �ٻ�ָ����ӳ�ս���ٻ�����滻����ǰ�ѳ�ս�����
        suicong hide �����       ���ٻ�����������ջ�
        suicong tiyan             ��ȡ1����ӽ������飬��ʽ���ź��ɾ��
TEXT);  
        
        if (wizardp(me))
        {
                write("\n        suicong chaplayer ID �����   �� �ɲ鿴ָ�����ָ�����������\n");
        }
        
        
        sMsg = "\n=--------------------------------------------------------------------------------------=\n";
        sMsg+= "��ǰ�ٻ���������У�" + HIG + SUICONG_D->get_sum(me) + "\n" NOR;
        sMsg+=   "=--------------------------------------------------------------------------------------=\n";
        write(sMsg);
        return 1;
}
