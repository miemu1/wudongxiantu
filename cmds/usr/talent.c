// This program is a part of NT MudLIB

#include <ansi.h>
#ifndef F_ABILITY;
#define F_ABILITY        "/adm/daemons/abilityd"
#endif

inherit F_ABILITY;
int main(object me, string arg)
{
        string *lists,temp,id;
        int ab;
        int i, a_num, learned_energy;
        object ob;
        string arg1, myclass,str;
        int level;

        MYGIFT_D->check_mygift(me, "newbie_mygift/talent");
        if( wizardp(me) )
        {
                if( arg && sscanf(arg, "-%s", id) == 1 )
                {
                        ob = present(id, environment(me));
                        if (!ob) ob = find_player(id);
                        if (!ob) ob = find_living(id);
                        if (!ob) return notify_fail("��Ҫ�쿴˭���츳���ܣ�\n");
                } else
                        ob = me;
        } else
                ob = me;

        ab = query("energy", ob);

        learned_energy=query("learned_energy", ob);

        if( arg && ob == me )
        {
                if( !sscanf(arg, "+ %d", a_num) )
                        return notify_fail("����츳���ܵĸ�ʽ��talent + �츳���ܴ��� \n");
                        
                if( a_num < 1 || a_num > 32 )
                        return notify_fail("û�д˴�����츳���ܣ�������1-30��\n");

                if( a_num < 33 )
                {
                        arg1 = talent_ability[a_num-1];
                        level = query("yuanshen_level", ob);
                        
                        if( a_num > (level/10 + 1) * 3 )
                                return notify_fail("���Ԫ�񾳽绹���������ո��ߵ��츳���ܡ�\n");   
     
                        if( !valid_ability_improve(ob, arg1, 2) )
                                return notify_fail("���Ԫ�񾳽绹���������ո��ߵĸ���������\n");
                                
                        if( !do_ability_cost(ob, arg1, 2) )
                                return notify_fail("��û���㹻���츳�㴢������ߴ���������\n");
                                
                        improve_ability(ob, arg1, 2);
                        tell_object(ob, "�õ�"+ (a_num) + "�츳���������ϡ�\n");
                        return 1;
                }

                return 1;
        }

        
        str = ZJOBLONG;
        str +=sprintf(HIY+(ob==me?"��":ob->query_idname())+HIY"���յ��츳��������\n"NOR);
        str +=sprintf(HIC    "���              ��Ч                      �ȼ�          ��������\n"NOR);
        str +=sprintf(HIG "������������������������������������\n" NOR);

        for(i=0; i<sizeof(talent_ability); i++)
        str+=(sprintf(ZJURL("cmds:talent + %d")+ZJSIZE(25)"���ӵ㡿", (i+1)) + HIC"\n"+ get_ability_info(ob, talent_ability[i], 2) + NOR);
		//str+=(sprintf(ZJURL("cmds:talent + %d")+ZJSIZE(25)"����5�㡿", (i+5)) + HIC"\n"+ get_ability_info(ob, talent_ability[i], 2) + NOR);
        str +=sprintf("\n");     
     
        str +=sprintf(HIG "������������������������������������\n" NOR);

        str +=sprintf(HIW"�������ܹ���� "HIC + ab + NOR+HIW" ���츳�㡣\n" NOR);
        str +=sprintf(HIW"���Ѿ���ȥ�� " RED+ learned_energy +NOR+HIW" ���츳�㣬��ʣ�� "HIG+ (ab-learned_energy) + NOR+HIW" ��ɹ����䡣\n" NOR);

      str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
	str = str[0..(strlen(str)-5)];
	str += "\n";
	message("vision", str, me);
        return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ :     talent [0m
[0;1;37m����������������������������������������������������������������[0m

talnet         ����֪����Ŀǰ�����յ�һ���츳���ܣ�
talent + n     ��ߵڣ����츳���ܵĵȼ���

���������ã�
    ��ҿ�������̶�̳Ǵ��������������������Ѿ�����õ��츳�㡣
���ú������츳���ܻ�ԭΪ�츳�㡣��һ�������츳������һ����
����֮��ÿ����һ�Σ����ٶ�������һ����������25�μ�֮�������
�������ٶ����������ģ��̶�ÿ��25��������

[0;1;37m����������������������������������������������������������������[0m
HELP
    );

        MYGIFT_D->check_mygift(me, "newbie_mygift/talent");
        return 1;
}
