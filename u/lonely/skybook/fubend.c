// ����ϵͳ�����ļ�
#define MEMBER_D          "/adm/daemons/memberd"

#include <ansi.h>

void move_all_invalid_user(object me); //�Ƴ�
int move_next_fb_room(object me, object ob_room, string into_msg, string into_msg_team, string fb_name, object last_room);

// ��������ʱ��
mapping fb_reset_time = ([
        "���"              : 6 * 3600,
        "������������"      : 6 * 3600,
        
]);

// �ƶ���ָ������ ����ǰPLAYER��PLAYERΪ�׵Ķ����ƶ����µĸ�������
// me, �¸���OB�����˽�����ʾ����ӽ�����ʾ
// ����nWhere = 1����Ӵ浵����� Ϊ0�����ڸ������ƶ�
// nWhere_save_point ����浵�� �� /fuben/���/save/��������
int move_new_fb(object me, object ob_room, string into_msg, string into_msg_team, string fb_name, int nWhere, string nWhere_save_point)
{
        object *t;
        object ob;
        object ob_shensheng, ob_huoyan;
        
        if (! objectp(me))return 0;
        if (! objectp(ob_room))return 0;        
        
        t = me->query_team();

        if (! MEMBER_D->is_valib_member(me->query("id")))
        {
                tell_object(me, "�㻹�Ƿǻ�Ա���޷����븱����\n");
                return 1;
        }
        if (! me->query("scborn/ok"))
        {
                tell_object(me, "�㻹δת�����޷����븱����\n");
                return 1;                       
        }
        
        if (me->query("combat_exp") < 10000000)
        {
                tell_object(me, "��ʵս��Ϊ���㣬�޷����븱����\n");
                return 1;                               
        }

        // δ�����ø������ܲ���
        if (! me->query("fuben/" + fb_name + "/open"))
        {
                tell_object(me, "�㻹δ����" + fb_name + "�������޷����룡\n");
                return 1;
        }

        // �����ڸ������ƶ�
        if (! nWhere)
        {
                return move_next_fb_room(me, ob_room, into_msg, into_msg_team, fb_name, 0);
        }
        
        // ������һ������������Ƿ���������ң������κ��˾����ɽ���
        if (! arrayp(t))
        {
        }
        t -= ({ 0 });
        if (! me->is_team_leader() || sizeof(t) < 1)
        {
        }
        else
        {
        }
        
        // ����ǴӴ浵����룬�����������ٴδ�ͷ����Ҳ���ǴӴ浵�����
        if (nWhere == 1)
        {
                // û�иô浵�����޷�����
                if (! me->query(nWhere_save_point))
                {
                        tell_object(me, "��û�иô浵�㣬�޷����룡\n");
                        return 1;
                }
        }
        
        // ��ѯ�ϴν��븱��������ʱ��
        if (time() - me->query("fuben/" + fb_name + "/last_join_time")  < fb_reset_time[fb_name])
        {
                tell_object(me, "������ϴν���" + fb_name + "������ʱ�޲������޷����룬 ָ�� fb list �ɲ鿴��ϸ�����\n");
                return 1;
        }

        // ���ϻ���֮�����㣬���޷�����
        if (! me->query("fuben/" + fb_name + "/first_open"))
        {
                if (! objectp(ob_huoyan = present("huoyan zhijing", me)))
                {
                        tell_object(me, "������û�л���֮�����޷��Ӵ浵������½��븱����\n");
                        return 1;
                }
        }
        else // ���������ɹ����״ν��벻�۳�����֮��
        {
                
        }
                
        if (! arrayp(t))
        {               
                // ���ϻ���֮�����㣬���޷�����
                if (! me->query("fuben/" + fb_name + "/first_open"))
                {
                        if (! objectp(ob_huoyan = present("huoyan zhijing", me)))
                        {
                                tell_object(me, "������û�л���֮�����޷��Ӵ浵������½��븱����\n");
                                return 1;
                        }
                        destruct(ob_huoyan);
                }
                else // ���������ɹ����״ν��벻�۳�����֮��
                {
                        me->set("fuben/" + fb_name + "/first_open", 0);
                }
                                
                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);
                
                me->move(ob_room);
                // ���ý��븱��ʱ��
                me->set("fuben/" + fb_name + "/last_join_time", time());
                me->save();
                return 1;
        }

        t -= ({ 0 });
        if (! me->is_team_leader() || sizeof(t) < 1)
        {
                // ���ϻ���֮�����㣬���޷�����
                if (! me->query("fuben/" + fb_name + "/first_open"))
                {
                        if (! objectp(ob_huoyan = present("huoyan zhijing", me)))
                        {
                                tell_object(me, "������û�л���֮�����޷��Ӵ浵������½��븱����\n");
                                return 1;
                        }
                        destruct(ob_huoyan);
                }
                else // ���������ɹ����״ν��벻�۳�����֮��
                {
                        me->set("fuben/" + fb_name + "/first_open", 0);
                }               

                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);
                
                me->move(ob_room);
                // ���ý��븱��ʱ��
                me->set("fuben/" + fb_name + "/last_join_time", time());
                me->save();
                return 1;               
        }

        foreach ( ob in t)
        {
                if (! MEMBER_D->is_valib_member(ob->query("id")))
                {
                        tell_object(ob, "�ǻ�Ա���޷����븱����\n");
                        continue;
                }
                if (! ob->query("scborn/ok"))
                {
                        tell_object(ob, "�㻹δת�����޷����븱����\n");
                        continue;
                }
                if (ob->query("combat_exp") < 10000000)
                {
                        tell_object(ob, "��ʵս��Ϊ���㣬�޷����븱����\n");    
                        continue;                       
                }
                // δ�����ø������ܲ���
                if (! ob->query("fuben/" + fb_name + "/open"))
                {
                        tell_object(ob, "�㻹δ����" + fb_name + "�������޷����룡\n");
                        return 1;
                }

                // ����Ѿ������˸ø�������ͷ�����������Ӵ浵�����
                if (! nWhere)
                {
                        if (ob->query("fuben/" + fb_name + "/open"))
                        {
                                nWhere = 1;
                                nWhere_save_point = "/fuben/" + fb_name + "/save/���¿�ʼ";
                        }
                }
                // ����ǴӴ浵�����
                if (nWhere == 1)
                {
                        // û�иô浵�����޷�����
                        if (! ob->query(nWhere_save_point))
                        {
                                tell_object(ob, "��û�иô浵�㣬�޷����룡\n");
                                continue;
                        }
                }       
                
                // ��ѯ�ϴν��븱��������ʱ��
                if (time() - ob->query("fuben/" + fb_name + "/last_join_time")  < fb_reset_time[fb_name])
                {
                        tell_object(ob, "������ϴν���" + fb_name + "������ʱ�޲������޷����룬 ָ�� fb list �ɲ鿴��ϸ�����\n");
                        continue;
                }

                // ���ϻ���֮�����㣬���޷�����
                if (! ob->query("fuben/" + fb_name + "/first_open"))
                {
                        if (! objectp(ob_huoyan = present("huoyan zhijing", ob)))
                        {
                                tell_object(ob, "������û�л���֮�����޷��Ӵ浵������½��븱����\n");
                                continue;
                        }
                        destruct(ob_huoyan);
                }
                else // ���������ɹ����״ν��벻�۳�����֮��
                {
                        ob->set("fuben/" + fb_name + "/first_open", 0);                 
                }

                tell_object(ob, HIG "\n��ӣ�" + into_msg_team + "\n\n" NOR);
                
                ob->move(ob_room);
                // ���ý��븱��ʱ��
                ob->set("fuben/" + fb_name + "/last_join_time", time());
                ob->save();
        }
        return 1;
}
// �������ƶ������ڽ�ָ���ӳ������ж����Աһ���ƶ�����һ����
int move_next_fb_room(object me, object ob_room, string into_msg, string into_msg_team, string fb_name, object last_room)
{
        object *t;
        object ob;
        
        if (! objectp(me))return 0;
        if (! objectp(ob_room))return 0;        
        
        t = me->query_team();

        if (! arrayp(t))
        {
                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);

                me->move(ob_room);
                
                if (objectp(last_room))destruct(last_room);
                
                return 1;
        }

        t -= ({ 0 });
        if (! me->is_team_leader() || sizeof(t) < 1)
        {

                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);
                
                me->move(ob_room);

                if (objectp(last_room))destruct(last_room);
                
                return 1;               
        }

        foreach ( ob in t)
        {

                tell_object(ob, HIG "\n��ӣ�" + into_msg_team + "\n\n" NOR);
                
                ob->move(ob_room);

        }
        
        if (objectp(last_room))destruct(last_room);
        return 1;
}

// ��սBOSS -- HELP BOSS�����ڽ�ָ���ӳ������ж����Աһ���ƶ�����һ����
// time_limit ʱ�����ƣ���ʾ��BOSS��������time_limit��ֻ����սһ��
int move_boss_fb_room(object me, object ob_room, string into_msg, string into_msg_team, string fb_name, object last_room, int time_limit, int cost)
{
        object *t;
        object ob;
        
        if (! objectp(me))return 0;
        if (! objectp(ob_room))return 0;        
        
        t = me->query_team();

        if (! arrayp(t))
        {
                if (time() - me->query(fb_name + "/last_time") < time_limit)
                {
                        tell_object(me, HIG "\n�㻹��Ҫ�ٵȴ�" + sprintf("%d", time_limit + me->query(fb_name + "/last_time") -time()) + 
                                              "�������ٴν���ÿռ䣡\n" NOR);
                        return 1;
                }
                
                if (me->query("stocks/balance") < cost)
                {
                        tell_object(me, HIG "\n���޷�֧������ռ�ķ��ã�������ֹ����ռ䡣\n" NOR);
                        return 1;
                }
                else
                {
                        me->add("stocks/balance", -1 * cost);
                        me->save();
                }
                
                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);

                move_all_invalid_user(me);
                
                me->move(ob_room);
                me->set(fb_name + "/last_time", time());

                if (ob_room->query("id") == "huashan zhidian")
                        MYGIFT_D->check_mygift(me, "newbie_mygift/joinfuben");
                
                me->save();
                if (objectp(last_room))destruct(last_room);
                
                return 1;
        }

        t -= ({ 0 });
        if (! me->is_team_leader() || sizeof(t) < 1)
        {

                if (time() - me->query(fb_name + "/last_time") < time_limit)
                {
                        tell_object(me, HIG "\n�㻹��Ҫ�ٵȴ�" + sprintf("%d", time_limit + me->query(fb_name + "/last_time") -time()) + 
                                              "�������ٴν���ÿռ䣡\n" NOR);
                        return 1;
                }
                
                if (me->query("stocks/balance") < cost)
                {
                        tell_object(me, HIG "\n���޷�֧������ռ�ķ��ã�������ֹ����ռ䡣\n" NOR);
                        return 1;
                }
                else
                {
                        me->add("stocks/balance", -1 * cost);
                        me->save();
                }
                                
                tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);
                
                move_all_invalid_user(me);
                
                me->move(ob_room);
                me->set(fb_name + "/last_time", time());
                
                if (ob_room->query("id") == "huashan zhidian")
                        MYGIFT_D->check_mygift(me, "newbie_mygift/joinfuben");
                
                
                me->save();
                if (objectp(last_room))destruct(last_room);
                
                return 1;               
        }

        // �����ж϶ӳ��Ƿ���Խ��룬����ӳ����ܽ������������鲻�ܽ���

        if (time() - me->query(fb_name + "/last_time") < time_limit)
        {
                tell_object(me, HIG "\n�㻹��Ҫ�ٵȴ�" + sprintf("%d", time_limit + me->query(fb_name + "/last_time") -time()) + 
                                      "�������ٴν���ÿռ䣡\n" NOR);
                return 1;
        }
        if (me->query("stocks/balance") < cost)
        {
                tell_object(me, HIG "\n���޷�֧������ռ�ķ��ã�������ֹ����ռ䡣\n" NOR);
                return 1;
        }

        foreach ( ob in t)
        {
                // �Ƕӳ����¼���time_limit
                if (! ob->is_team_leader())
                {
                        object obj;
                        mapping boss_list;
                        string *keys_boss_list;
                        int new_time_limit;
                        
                        if (! objectp(obj = find_object("/kungfu/class/misc/fuben/boss/jieyinshi")))
                                obj = load_object("/kungfu/class/misc/fuben/boss/jieyinshi");
                        
                        boss_list = obj->show_time_delay(1);
                        keys_boss_list = explode(boss_list[fb_name], ":");
                        sscanf(keys_boss_list[3], "%d", new_time_limit);
                        time_limit = new_time_limit * 3600;
                        
                        // vip������ȴʱ��
                        switch(ob->GetVipLevel())
                        {
                        case 1:
                                time_limit = time_limit - time_limit / 10;
                        break;
                        case 2:
                                time_limit = time_limit - time_limit * 2 / 10;
                        break;
                        case 3:
                                time_limit = time_limit - time_limit * 3 / 10;  
                        break;
                        case 4:
                                time_limit = time_limit - time_limit * 4 / 10;  
                        break;
                        case 5:
                                time_limit = time_limit - time_limit * 5 / 10;  
                        break;
                        case 6:
                                time_limit = time_limit - time_limit * 6 / 10;  
                        break;                                  
                        }
                        // ��ˬ���ջ
                        if (MEMBER_D->ifdatein("2013-5-25", "2013-6-20") == 1)
                        {
                                time_limit /= 2;
                        }
                        
                }

                if (time() - ob->query(fb_name + "/last_time") < time_limit)
                {
                        tell_object(ob, HIG "\n�㻹��Ҫ�ٵȴ�" + sprintf("%d", time_limit + ob->query(fb_name + "/last_time") -time()) + 
                                              "�������ٴν���ÿռ䣡\n" NOR);
                        continue;
                }
                
                if (ob->query("stocks/balance") < cost)
                {
                        tell_object(ob, HIG "\n���޷�֧������ռ�ķ��ã�������ֹ����ռ䡣\n" NOR);
                        continue;
                }
                else
                {
                        ob->add("stocks/balance", -1 * cost);
                        ob->save();
                }

                tell_object(ob, HIG "\n��ӣ�" + into_msg_team + "\n\n" NOR);
                
                move_all_invalid_user(ob);
                
                ob->move(ob_room);
                ob->set(fb_name + "/last_time", time());
                
                if (ob_room->query("id") == "huashan zhidian")
                        MYGIFT_D->check_mygift(ob, "newbie_mygift/joinfuben");
                
                ob->save();
        }
        
        if (objectp(last_room))destruct(last_room);
        return 1;
}

void move_all_invalid_user(object me)
{
        int i;
        object *inv;

                        
        // �ѱ�����û�������
        inv = deep_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
        {
                if (! playerp(inv[i])) continue;

                // ���˱�����û�
                inv[i]->move(environment(me));                
        }
        
}

// ���˸�����ֻ�ƶ���ǰplayer,���ϣ����ϣ�������е�player�����ƶ�
int move_lonely_fb_room(object me, object ob_room, string into_msg, string into_msg_team, string fb_name)
{
        object ob;
        
        if (! objectp(me))return 0;
        if (! objectp(ob_room))return 0;        
        
        tell_object(me, HIG "\n" + into_msg + "\n\n" NOR);

        // �Ƴ����зǷ������û�
        move_all_invalid_user(me);

        me->move(ob_room);
        me->save();
        
        return 1;


        return 1;
}
