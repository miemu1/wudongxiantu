//arm.c

#include <ansi.h>
#include <tomud.h>
#include <combat.h>
inherit F_CLEAN_UP;

string name_temp(object ob,string type);

int main(object me, string arg)
{
	int i;
	object ob;
	mapping prepare;
	int attack_points, dodge_points, parry_points,islook;
	object weapon,second_weapon;
	string line,tmp,wp1,wp2,skill_type;

	if (arg)
	{
		ob = find_player(arg);
		if (! ob) ob = find_living(arg);
		if (! ob) ob = present(arg, environment(me));
		if (! wizardp(me) && (! ob || me->query("couple/child") != ob->query("id")))
		{
		      islook=0;   //������ʦ���Ӳ��ܿ����幥��������ֵ
		}
		else
		{
		      islook=1;       //���Բ鿴ȫ����ֵ
		}
		if(!ob)
		{
		     return notify_fail("��Ҫ�쿴˭��װ����\n");
		}
	}
	if (! ob)
	{
		ob = me;
	      islook=1;       //���Բ鿴ȫ����ֵ
	}
	if( ob==me && me->is_ghost() )
		return notify_fail("��Щ����֮�����������������ȥ���������˰ɣ�\n");

	line="";
	tmp=ZJOBACTS2+ZJMENUF(2,2,10,30);
	wp1="��:null"ZJSEP;
	wp2="��:null"ZJSEP;

	weapon= ob->query_temp("weapon");
	second_weapon= ob->query_temp("secondary_weapon");
	if(weapon)
	{
		wp1=weapon->query("name")+":look "+weapon->query("id")+ZJSEP;
	}
	if(second_weapon)
	{
		  wp2=second_weapon->query("name")+":look "+weapon->query("id");
	}

	line += BBLU+" ["+ob->query("name")+"] ��װ���������£�"NOR"\n";
	line += sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
	line += ob->suit(ob);   //��װ��Ϣ
	line += sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
	if(islook)
	{
		prepare = me->query_skill_prepare();
		if( objectp(weapon = ob->query_temp("weapon")) )
			skill_type = weapon->query("skill_type");
		else if (prepare&&sizeof(prepare)>0)  skill_type = (keys(prepare))[0];
		else
			skill_type = "unarmed";

		attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
		parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
		dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
		line += sprintf("��   ս�������� " HIW "%8d  "NOR" ս�������� " HIW "%8d "NOR"\n",attack_points /100000  + 1, (dodge_points + (weapon? parry_points: (parry_points/10))) /100000  + 1);
		line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
		line += sprintf("��   �����˺��� " HIC "%8d  "NOR" װ�������� "HIC"%8d"NOR"\n", ob->query_temp("apply/damage"),ob->query_temp("apply/armor") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   �о������� " HIC "%8d  "NOR" ѧϰ������ "HIC"%8d"NOR"\n", ob->query("research_times"),ob->query("xuexi_times") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   Ѫ�����ޣ� " HIC "%8d  "NOR" �������ޣ� "HIC"%8d"NOR"\n", ob->query("xueliang"),ob->query("jli") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   �������У� " HIC "%8d  "NOR" ��Ĭ������ "HIC"%8d"NOR"\n", ob->query("apply/xuruo_perform"),ob->query("apply/no_perform") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   �����˺��� " HIC "%8d  "NOR" ����æ�ң� "HIC"%8d"NOR"\n", ob->query("reduce_damage"),ob->query("reduce_busy") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ׷���˺��� " HIC "%8d  "NOR" �����˺��� "HIC"%8d"NOR"\n", ob->query("apply/add_damage"),ob->query("apply/xuruo_damage") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ս�������� " HIC "%8d  "NOR" ���з����� "HIC"%8d"NOR"\n", ob->query("apply/xuruo_status"),ob->query("apply/perform_dp") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ׷�ӷ����� " HIC "%8d  "NOR" ��Ϣ���ң� "HIC"%8d"NOR"\n", ob->query("apply/add_armor"),ob->query("apply/no_exert") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   æ�ҵ��ˣ� " HIC "%8d  "NOR" ���мӳɣ� "HIC"%8d"NOR"\n", ob->query("apply/busy_time"),ob->query("apply/attack") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ����͵ȡ�� " HIC "%8d  "NOR" ����͵ȡ�� "HIC"%8d"NOR"\n", ob->query("apply/leech_qi"),ob->query("apply/leech_neili") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ˫���˺��� " HIC "%8d  "NOR" ��ת������ "HIC"%8d"NOR"\n", ob->query("apply/double_damage"),ob->query("apply/qi_abs_neili") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ��͸���ף� " HIC "%8d  "NOR" �����ָ��� "HIC"%8d"NOR"\n", ob->query("apply/through_armor"),ob->query("apply/neili_recover") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   �����ָ��� " HIC "%8d  "NOR" �����ָ��� "HIC"%8d"NOR"\n", ob->query("apply/qi_recover"),ob->query("apply/jing_recover") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ��֮�˺��� " HIC "%8d  "NOR" ħ֮�˺��� "HIC"%8d"NOR"\n", ob->query("apply/add_poison"),ob->query("apply/add_magic") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ��֮�˺��� " HIC "%8d  "NOR" ľ֮�˺��� "HIC"%8d"NOR"\n", ob->query("apply/add_metal"),ob->query("apply/add_wood") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ˮ֮�˺��� " HIC "%8d  "NOR" ��֮�˺��� "HIC"%8d"NOR"\n", ob->query("apply/add_water"),ob->query("apply/add_fire") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ��֮�˺��� " HIC "%8d  "NOR" ���˿��ԣ� "HIC"%8d"NOR"\n", ob->query("apply/add_earth"),ob->query("apply/reduce_poison") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ħ�˿��ԣ� " HIC "%8d  "NOR" ���˿��ԣ� "HIC"%8d"NOR"\n", ob->query("apply/reduce_magic"),ob->query("apply/reduce_metal") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ľ�˿��ԣ� " HIC "%8d  "NOR" ˮ�˿��ԣ� "HIC"%8d"NOR"\n", ob->query("apply/reduce_wood"),ob->query("apply/reduce_water") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ���˿��ԣ� " HIC "%8d  "NOR" ���˿��ԣ� "HIC"%8d"NOR"\n", ob->query("apply/reduce_fire"),ob->query("apply/reduce_earth") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ���Ӷ��ˣ� " HIC "%8d  "NOR" ��ä���ʣ� "HIC"%8d"NOR"\n", ob->query("apply/avoid_poison"),ob->query("apply/add_blind") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   �������ʣ� " HIC "%8d  "NOR" �������ʣ� "HIC"%8d"NOR"\n", ob->query("apply/add_freeze"),ob->query("apply/add_forget") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   �������ʣ� " HIC "%8d  "NOR" æ�Ҹ��ʣ� "HIC"%8d"NOR"\n", ob->query("apply/add_weak"),ob->query("apply/add_busy") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ������ä�� " HIC "%8d  "NOR" ���ӱ����� "HIC"%8d"NOR"\n", ob->query("apply/avoid_blind"),ob->query("apply/avoid_freeze") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ���������� " HIC "%8d  "NOR" ���������� "HIC"%8d"NOR"\n", ob->query("apply/avoid_forget"),ob->query("apply/avoid_weak") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ����æ�ң� " HIC "%8d  "NOR" ����æ�ң� "HIC"%8d"NOR"\n", ob->query("apply/avoid_busy"),ob->query("apply/reduce_busy") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ���ӿ־壺 " HIC "%8d  "NOR" ����һ���� "HIC"%8d"NOR"\n", ob->query("apply/avoid_fear"),ob->query("apply/fatal_blow") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ���繥���� " HIC "%8d  "NOR" �䶳������ "HIC"%8d"NOR"\n", ob->query("apply/resistance/lighting"),ob->query("apply/resistance/cold") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
line += sprintf("��   ���湥���� " HIC "%8d  "NOR" ħ�������� "HIC"%8d"NOR"\n", ob->query("apply/resistance/fire"),ob->query("apply/resistance/magic") );
line+= sprintf(HIC"��"BGRN"����������������������"BGRN"��"NOR"\n");
	}
	// ��������ɫ��������(���ɫ��Ų��ᱻ���ȥ�����ҵ�)
//	if(!arg)
//		tmp += "[����װ��]:wear all"ZJSEP"[�ѵ�װ��]:remove all"ZJSEP;
//	    tmp += "[ �� �� װ �� ]:summon all"ZJSEP;
//        tmp += "[�ֳ�����]:wield all"ZJSEP"[��������]:unwield all"ZJSEP;

//	tmp += sprintf("[����]��%s[����]��%s",wp1, wp2);
//	tmp += sprintf("[����]��%s[����]��%s", name_temp(ob,"armor/face"), name_temp(ob,"armor/wrists"));
//	tmp += sprintf("[����]��%s[�ֲ�]��%s", name_temp(ob,"armor/neck"), name_temp(ob,"armor/hands"));
//	tmp += sprintf("[�·�]��%s[����]��%s",name_temp(ob,"armor/cloth"), name_temp(ob,"armor/armor"));
//	tmp += sprintf("[����]��%s[����]��%s", name_temp(ob,"armor/shield"),name_temp(ob,"armor/waist"));
//	tmp += sprintf("[ͷ��]��%s[����]��%s",name_temp(ob,"armor/head"), name_temp(ob,"armor/pants"));
//	tmp += sprintf("[��ָ]��%s[�㲿]��%s", name_temp(ob,"armor/finger"), name_temp(ob,"armor/boots"));
	line = replace_string(line,"\n",ZJBR)+"\n";
//	line += tmp;
	write(ZJOBLONG+line+"\n");

	return 1;

}

int help (object me)
{
	write(@HELP
ָ���ʽ: arm

���г���(��)Ŀǰ������Я����������Ʒ��


HELP );
	return 1;
}