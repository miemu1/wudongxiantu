// research.c

#include <skill.h>
#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int *query_scale(string skill);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);
	string skill, skill_name;
	int jing_cost, times;
	int is_force_skill;
	int is_parry_skill;
	mapping lrn,skl;
	int intlv,lvl;
	string *ks;
	int *ls, *scale;
	int improve;
	int mlvl;
	int i,a,b,c,k;
	string type;
	int t = time();
	int spi;
	int lvl_name;

	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if (t == me->query_temp("time/research"))
		return notify_fail("��ող��о����������Ҫ�����о�������ָ���о��Ĵ�������\n");

	if (environment(me)->query("no_learn") || environment(me)->query("no_fight"))
		return notify_fail("����̫���ӣ���û�����о���\n");

	if (! arg)
		return notify_fail("research|yanjiu <����> <����>\n");

	if (sscanf(arg, "%s %d", skill, times) != 2)
	{
		skill = arg;
		return notify_fail(INPUTTXT("�������о�������","yanjiu "+arg+" $txt#")+"\n");
	}
    
	if (times!=1&&times!=10)
		return notify_fail("�о�����ֻ����һ�λ���ʮ�Ρ�\n");

	if (me->is_fighting())
		return notify_fail("����ĥǹ������������\n");

	if (! (lvl = me->query_skill(skill, 1)))
		return notify_fail("������㻹���ᣬ�о�ʲô��\n");

	if ((string) SKILL_D(skill)->type() == "knowledge")
		return notify_fail(to_chinese(skill) + "ֻ�ܿ���ѧϰ������ߵġ�\n");

	if (lvl < 150)
		return notify_fail("���" + to_chinese(skill) + "�����ճ̶Ȼ�δ���о��ĳ̶ȡ�\n");

	notify_fail("����Ŀǰ��������û�а취�о����ּ��ܡ�\n");
	if (! SKILL_D(skill)->valid_learn(me) ||
	    ! SKILL_D(skill)->valid_research(me))
		// ����ѧϰ���ǲ����о�
		return 0;

	if (! XUE_CMD->can_learn(me, skill))
		return 0;

	// Lookup skills for relation skills

	write(HIG "�㿪ʼ�о�" + chinese_number(times) + "���йء�" + to_chinese(skill) + "���İ��ء�"NOR"\n");
	message("vision", me->name() + "��ڤ��˼����\n", where, ({ me }));

	if(lvl<380)
		intlv = me->query("int");
	else
		intlv = 10 + me->query("int")*3/4;
	// calculate the basic effect
	is_force_skill = SKILL_D(skill)->valid_enable("force");
	is_parry_skill = SKILL_D(skill)->valid_enable("parry") && (! is_force_skill);
	ks = keys(me->query_skills());
	ls = ({ });
	for (i = 0; i < sizeof(ks); i++)
	{
		mapping action;
		int eff;

		if (ks[i] == skill) continue;
		if (SKILL_D(ks[i])->main_skill() &&
		    SKILL_D(ks[i])->main_skill() != ks[i]) continue;
		if (SKILL_D(skill)->valid_enable(ks[i]))
			ls += ({ me->query_skill(ks[i], 1) });
		if (SKILL_D(ks[i])->valid_enable(skill) ||
		    is_force_skill && SKILL_D(ks[i])->valid_enable("force"))
		{
			// Relation skill
			action = SKILL_D(ks[i])->query_action(me, 0);
			eff = (int)me->query_skill(ks[i], 1);
			if (action)
			{
				// do more effect
				eff += (action["force"] + action["damage"] +
					action["attack"] + action["parry"] +
					action["dodge"]) * eff / 1000;
			}
				
			ls += ({ eff });
		}
	}
	ls = sort_array(ls, -1);
	scale = query_scale(skill);
	improve = 0;
	for (i = 0; i < sizeof(ls) && i < sizeof(scale); i++)
		improve += ls[i] * scale[i];

	improve = improve / 10 / (100 + SKILL_D(skill)->difficult_level()) + intlv / 2;
	improve += lvl / 30;
	improve += improve * where->query("research_improve") / 100;
	if (lvl > 500)
		improve /= lvl / 100 - 5 + 2;
	if (intlv >23)
		improve += improve*(intlv-23)*4/300;
	if (improve < 2)
		improve = 2;
	jing_cost = 1000 / intlv;
	if ((int)me->query("eff_jing") < jing_cost)
		return notify_fail("������㾫�����ã�ʵ��û�а취�����о���\n");

	if (! me->can_improve_skill(skill))
	{
		write("Ҳ����ȱ��ʵս��Ϊ����е����Լ����о�" + to_chinese(skill) + "�������ˡ�\n");
		return 1;
	}

	me->set_temp("time/research", t);
	for (i = 0; i < times; i++)
	{
    		if ((int)me->query("jing") < jing_cost)
		{
			if (me->query("env/auto_regenerate") &&
			    SKILL_D("force/regenerate")->exert(me, me))
			{
				// try to regenerate & learn again
				write("����þ������һЩ�����������о���\n");
				i--;
				continue;
			} else
			{
				me->set("jing", 0);
				break;
			}
		}

	    skl = me->query_skills();
	    lrn = me->query_learned();
		b=skl[skill];
	    if (! mapp(lrn)) lrn = ([]);
		a=(improve-1)/2;
		c=(b+1)*(b+1)-lrn[skill];
	    type = SKILL_D(skill)->type();
	    switch (type)
	    {
	     case "martial":
		    if (intp(mlvl =me->query_skill("martial-cognize")) &&
		    skill != "martial-cognize")
			a += a * mlvl / 500;
		     break;

	    case "knowledge":
		    if (intp(mlvl =me->query_skill("culture-cognize")) &&
		    skill != "culture-cognize")
			a += a * mlvl / 500;
		    break;

	    case "technic":
		    if (intp(mlvl =me->query_skill("technic-cognize")) &&
		    skill != "technic-cognize")
			a += a * mlvl / 500;
		    break;
	    }
	    a = 1 + a * 100 / (b + 100);
		k=(c/a)+1;
	if ((me->query("potential") - me->query("learned_points")) < (1*k))
		return notify_fail("���Ǳ�ܲ����о��ˡ�\n");
		tell_object(me,HIG"�㻨���ˡ�"HIC+k+HIG"����Ǳ�ܣ�������һ����"HIC+to_chinese(skill)+HIG"��"NOR"\n");
		me->improve_skill(skill, a*k);
		me->add("learned_points", 1*k);
 
	}
       tell_object(me,ZJFORCECMD("yanjiu "+skill+""));
	if (! i && times==0 )
		write("�����̫���ˣ����ʲôҲû���о��ɡ�\n");
	return 1;
}

int *query_scale(string skill)
{
	if (SKILL_D(skill)->valid_enable("force")) skill = "force";
	switch (skill)
	{
	case "parry": return ({ 5, 20, 140, 70, 50, 30, 10, 5, 4, 3, 2, 1 });
	case "dodge": return ({ 80, 100, 30, 10, 8, 5, 2, 1 });
	case "force": return ({ 150, 120, 50, 40, 20, 8, 5, 2, 1 });
	default:      return ({ 80, 120, 90, 55, 30, 15, 5, 2, 1 });
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ : research | yanjiu <����> <����>
 
���ָ����������о�һ�ּ��ܵ��������⣬����ʦ������ܵļ�
�������ʱ�򣬿���ͨ���о��Լ�����ߣ����ȵ��ٶ�Ҫ�������
��ܵ����ճ̶Ⱥ���ؼ��ܵ���Ϥ�����أ���Ȼ����Ҳ�����һ
�������ã����ǹؼ����ǿ����ܵ�ˮƽ��һ����˵��صļ���Խ��Խ
�ã��о��������ܻ��°빦����������̫�٣�����ǡǡ�෴��

�������ָ�� : apprentice, practice, skills, study, learn
HELP );
	return 1;
}
