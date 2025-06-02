
/***************************************************
dialogd.c
***************************************************/
#include <ansi.h>

inherit F_DBASE;

// ָ��ʱ���Ƿ�Ϊ��ĩ
public int is_weekend_at(int t)
{       
        string str_ctime;


        // �ж�ָ��ʱ���Ƿ�Ϊ��ĩ
        if (t > 0)
        {
                if (sscanf(ctime(t), "Sat %s", str_ctime) || sscanf(ctime(t), "Sun %s", str_ctime))
                        return 1;               
                else
                        return 0;
        }
        
        return 0;
}

int weekend()
{
        string str_ctime;
                
        // ��ǰʱ���Ƿ�Ϊ��ĩ
        if (sscanf(ctime(time()), "Sat %s", str_ctime) || sscanf(ctime(time()), "Sun %s", str_ctime))
                return 1;

        return 0;               
}

// ��ǰʱ���Ƿ�Ϊ��ĩ
public int is_weekend()
{
        

        // ������20:00��ʼ��������23��59Ϊ��ĩ
        if (weekend() || 
            is_weekend_at(time() + 4 * 3600))   // ����20��00��
            return 1;
            
        return 0;
        
}

// ָ��ʱ�����ܼ�
/*
Mon  - 1
Tue  - 2
Wed  - 3
Thu  - 4
Fri  - 5
Sat  - 6
Sun  - 7
*/
public int weeknum(int t)
{
        string stmp, swk;
        
        mapping wk = ([
                "Mon" : 1,
                "Tue" : 2,
                "Wed" : 3,
                "Thu" : 4,
                "Fri" : 5,
                "Sat" : 6,
                "Sun" : 7,
        ]);
        
        if (sscanf(ctime(t), "%s %s", swk, stmp) == 2)
                return wk[swk];

        return 0;
}

void create() 
{
        seteuid(ROOT_UID);
        set("channel_id", "�Ի�����");
        set("name", HIW "�Ի�����" HIM);

        // ��ʱ�����ͷ���ĩ��Ϣ
        remove_call_out("broad_weekendinfo");
        call_out("broad_weekendinfo", 3600);
}

// �����ͷ���ĩ��Ϣ
void broad_weekendinfo()
{
        remove_call_out("broad_weekendinfo");
        call_out("broad_weekendinfo", 3600);
        
        if (is_weekend())
        {
                message_system(HIY "�׻�" HIG "��" HIM "��" HIC "��" HIM "ĩ" HIY
                               "���Ƚ����У����������� " HIR "wkgift info" HIY " �鿴�� \n" NOR);
        }       

        return;
}

// ģ��Ի�ģʽ�����Ϣ���������1���˿���������˵��NPC������ͬһ����
public void start_dialog(object npc, object me, string *msg, int index, int flag)
{

        if (! objectp(npc) || ! objectp(me))return;
        
        if (index == 0)
        {
                if (me->query_temp("is_in_dialog"))
                {
                        tell_object(me, HIR "�����ڽ����龰�Ի�����£����Ժ����Ի��˳�(exit)��Ϸ�����µ�¼��\n" NOR);
                        return;
                }
                else
                {
                        me->set_temp("is_in_dialog", 1);
                }
        }
        
        if (environment(npc) != environment(me))
        {
                me->delete_temp("is_in_dialog");
                return;
        }
        
        // �Ի����������лص�
        if (index >= sizeof(msg))
        {
                me->delete_temp("is_in_dialog");
                npc->dialog_end(me, flag);
                return;
        }
        
        if (index % 2 == 1)             
                tell_object(me, HIY + "=" + msg[index] + "\n" NOR);
        else
                tell_object(me, HIM + "=" + msg[index] + "\n" NOR);     

        index += 1;

        call_out("start_dialog", 6, npc, me, msg, index, flag);

        return;
}

// ģ��Ի�ģʽ�����Ϣ����Χ�����������˿���������˵��NPC������ͬһ����
public void start_dialog2(object npc, object me, string *msg, int index, int flag)
{

        if (! objectp(npc) || ! objectp(me))return;
        
        if (index == 0)
        {
                if (me->query_temp("is_in_dialog"))
                {
                        tell_object(me, HIR "�����ڽ����龰�Ի�����£����Ժ����Ի��˳�(exit)��Ϸ�����µ�¼��\n" NOR);
                        return;
                }
                else
                {
                        me->set_temp("is_in_dialog", 1);
                }
        }

        if (environment(npc) != environment(me))
        {
                me->delete_temp("is_in_dialog");
                return;
        }


        // �Ի����������лص�
        if (index >= sizeof(msg))
        {
                me->delete_temp("is_in_dialog");
                npc->dialog_end(me, flag);              
                return;
        }
        
        if (index % 2 == 1)             
                message_vision(HIY + "=" + msg[index] + "\n" NOR, npc, me);
        else
                message_vision(HIM + "=" + msg[index] + "\n" NOR, npc, me);

        index += 1;

        call_out("start_dialog2", 6, npc, me, msg, index, flag);

        return;
}

// ģ��Ի�ģʽ�����Ϣ����Χ���������˿�����ֻҪ�����������ʲô�ط������Կ����Ի����
public void start_dialog3(object npc, object me, string *msg, int index, int flag)
{

        if (! objectp(npc) || ! objectp(me))return;
        
        // if (environment(npc) != environment(me))return;
        
        if (index == 0)
        {
                if (me->query_temp("is_in_dialog"))
                {
                        tell_object(me, HIR "�����ڽ����龰�Ի�����£����Ժ����Ի��˳�(exit)��Ϸ�����µ�¼��\n" NOR);
                        return;
                }
                else
                {
                        me->set_temp("is_in_dialog", 1);
                }
        }
                
        // �Ի����������лص�
        if (index >= sizeof(msg))
        {
                me->delete_temp("is_in_dialog");
                npc->dialog_end(me, flag);
                return;
        }
        
        if (index % 2 == 1)             
                message_vision(HIM + "=" + msg[index] + "\n" NOR, npc, me);
        else
                message_vision(HIM + "=" + msg[index] + "\n" NOR, npc, me);

        index += 1;

        call_out("start_dialog3", 6, npc, me, msg, index, flag);

        return;
}


// ģ��Ի�ģʽ�����Ϣ��ֻ�����һ�˿�����ֻҪ�����������ʲô�ط������Կ����Ի����
public void start_dialog4(object npc, object me, string *msg, int index, int flag)
{

        if (! objectp(npc) || ! objectp(me))return;
        
        // if (environment(npc) != environment(me))return;
        
        if (index == 0)
        {
                if (me->query_temp("is_in_dialog"))
                {
                        tell_object(me, HIR "�����ڽ����龰�Ի�����£����Ժ����Ի��˳�(exit)��Ϸ�����µ�¼��\n" NOR);
                        return;
                }
                else
                {
                        me->set_temp("is_in_dialog", 1);
                }
        }
                
        // �Ի����������лص�
        if (index >= sizeof(msg))
        {
                me->delete_temp("is_in_dialog");
                npc->dialog_end(me, flag);              
                return;
        }

        if (index % 2 == 1)             
                tell_object(me, HIY + "=" + msg[index] + "\n" NOR, npc);
        else
                tell_object(me, HIM + "=" + msg[index] + "\n" NOR, npc);

        index += 1;

        call_out("start_dialog4", 6, npc, me, msg, index, flag);

        return;
}
