#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string poision;
        
        // ��ʾ����ս״̬
        // ����XYWAR_D->now_status()
        if (! arg)
        {
                return 1;
        }
        
        // ��ʾ����ʿ�����
        if (arg == "soldier")
        {
                if (me->is_busy())return notify_fail("����æ�ء�\n");
                
                if (XYWAR_D->now_status() != 2 && XYWAR_D->now_status() != 3 && ! wizardp(me))
                        return notify_fail("��������սĿǰ��û�п�ʼ���޷��鿴��\n");
                
                XYWAR_D->show_soldier(me);
                return 1;
        }
        
        // ���������ؾ���ֻ����ҽ���ſ��Ե���
        if (sscanf(arg, "xmove %s", poision))
        {
                if (XYWAR_D->leader_player() != me->query("id") && ! wizardp(me))
                        return notify_fail("�Բ�����û��Ȩ�����������ؾ���\n");
                
                XYWAR_D->move_xysoldier(me, poision);
                
                return 1;
        }
                
        // �����ɹž�
        // ֻ����ʦ��Ȩ��
        if (arg == "add mgb" && wizardp(me))
        {
                
                // �����ɹű�ʱ����ADD_MGB_TIME
                /*
                if (time() - last_add_mgb_time < 120)
                {
                        return notify_fail("�ɹű�����Ԯ�������������䲻������\n");
                }
                */
                XYWAR_D->combat_add_soldier();
                return 1;
        }
        
        me->start_busy(2);
        return 1;
}


int help (object me)
{
        write(@HELP


HELP);
        return 1;
}

