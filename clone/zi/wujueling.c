// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "�������" NOR, ({ "wujue ling" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��ɽ֮�ۣ�Ⱥ��������С������֮�����ܻ�õ����ƣ�ƾ�������ѧϰһ�������ɵ���ѧ��ÿ������һ�Ρ�\n");
		set("unit", "��");
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_put",1);
        set("no_steal",1);
		set("action_list",([
			"ʹ��":"taojiao",
		]));
		set("no_sell", 1);set("value", 50000);
		set("gongxian", 15000);
		set("weight", 1);
	}
	setup();
}

void init()
{
	add_action("do_taojiao","taojiao");
}

int do_taojiao(string arg)
{
	string str,*fams,family,skill,skill_name,*skills;
	int i;
	object me;
	mapping mskills;
	mapping all_fam = ([
		"�䵱��":({
				"taiji-quan",
				"taiji-shengong",
				"wudang-xinfa",
				"tiyunzong",
				"wudang-zhang",
				"paiyun-shou",
				"wudang-jian",
				"taiji-jian",
				"taiji-dao",
				"raozhi-roujian",
				"huzhua-shou",
				"zhenshan-zhang",
				"yitian-zhang",
				"shenmen-jian",
				"xuanxu-dao",
				"yitian-zhang",
				"shenmen-jian",
			}),
		"������":({
				"jingang-buhuaiti",
                "banruo-zhang",
                "jingang-zhi",
                "jingang-quan",
                "xumishan-zhang",
				"cibei-dao",
				"damo-jian",
				"fengyun-shou",
				"fumo-jian",
				"hunyuan-yiqi",
				"shaolin-xinfa",
				"jingang-quan",
				"longzhua-gong",
				"luohan-quan",
				"nianhua-zhi",
				"pudu-zhang",
				"qianye-shou",
				"sanhua-zhang",
				"riyue-bian",
				"shaolin-shenfa",
				"weituo-gun",
				"wuchang-zhang",
				"xiuluo-dao",
				"yingzhua-gong",
				"yijinjing",
				"yizhi-chan",
				"zui-gun",
				"yipai-liangsan",
				"xiuluo-zhi",
				"duoluoye-zhi",
				"wuxiang-zhi",
			}),
		"������":({
				"kurong-changong",
				"duanshi-xinfa",
				"tiannan-step",
				"sun-finger",
			}),
		"��ɽ��":({
				"huashan-sword",
				"huashan-xinfa",
				"huashan-quanfa",
				"huashan-shenfa",
				"zixia-shengong",
				"poyu-quan",
				"hunyuan-zhang",
				"feiyan-huixiang",
				"kuangfeng-jian",
				"yunu-sword",
				"fanliangyi-dao",
			}),
		"��ɽ����":({
				"huashan-sword",
				"huashan-xinfa",
				"huashan-quanfa",
				"huashan-shenfa",
				"zixia-shengong",
				"poyu-quan",
				"hunyuan-zhang",
				"feiyan-huixiang",
				"kuangfeng-jian",
				"yunu-sword",
				"fanliangyi-dao",
			}),
		"������":({
				"persuading",
				"jinding-zhang",
				"tiangang-zhi",
				"huifeng-jian",
				"yanxing-dao",
				"zhutian-bu",
				"emei-xinfa",
				"linji-zhuang",
				"piaoxue-zhang",
				"jiuyin-baiguzhao",
			}),
		"�һ���":({
				"bibo-shengong",
				"luoying-xinfa",
				"tanzhi-shentong",
				"luoying-shenzhang",
				"xuanfeng-leg",
				"anying-fuxiang",
				"luoying-shenjian",
				"yuxiao-jian",
				"lanhua-shou",
				"bihai-chaosheng",
			}),
		"������":({
				"shenlong-xinfa",
				"yixingbu",
				"shenlong-bashi",
				"huagu-mianzhang",
				"shedao-qigong",
			}),
		"ؤ��":({
				"jiaohua-neigong",
				"huntian-qigong",
				"changquan",
				"xiaoyaoyou",
				"feiyan-zoubi",
				"dragon-strike",
				"jiaohua-bangfa",
				"dagou-bang",
				"mantianhuayu-zhen",
				"jueming-tui",
				"chansi-shou",
				"suohou-gong",
				"fengmo-zhang",
				"fumo-zhang",
			}),
		"��Ĺ��":({
				"yunv-xinfa",
				"surge-force",
				"yunv-jian",
				"quanzhen-jian",
				"xuantie-jian",
				"yunv-shenfa",
				"meinv-quan",
				"sad-strike",
				"fireice-strike",
				"tianluo-diwang",
				"yufeng-zhen",
				"yinsuo-jinling",
				"tianluo-diwang",
			}),
		"ȫ���":({
				"quanzhen-xinfa",
				"xiantian-gong",
				"quanzhen-jian",
				"jinyan-gong",
				"jinguan-yusuo",
				"chongyang-shenzhang",
				"haotian-zhang",
				"zhongnan-zhi",
			}),
		"������":({
				"huagong-dafa",
				"freezing-force",
				"guixi-gong",
				"feixing-shu",
				"zhaixinggong",
				"chousui-zhang",
				"sanyin-wugongzhao",
				"chanhun-suo",
				"tianshan-zhang",
			}),
		"��ң��":({
				"xiaoyao-xinfa",
				"beiming-shengong",
				"xiaowuxiang",
				"lingbo-weibu",
				"feiyan-zoubi",
				"liuyang-zhang",
				"ruyi-dao",
				"zhemei-shou",
			}),
		"ѩɽ��":({
				"longxiang",
				"mizong-neigong",
				"mingwang-jian",
				"xiangmo-chu",
				"riyue-lun",
				"shenkong-xing",
				"dashou-yin",
				"yujiamu-quan",
				"xiaowuxiang",
				"huoyan-dao",
			}),
		"Ѫ����":({
				"xue-dao",
				"mingwang-jian",
				"mizong-neigong",
				"xuehai-mogong",
				"shenkong-xing",
				"dashou-yin",
				"yujiamu-quan",
			}),

		"���չ�":({
				"zhemei-shou",
				"liuyang-zhang",
				"yueying-wubu",
				"bahuang-gong",
				"tianyu-qijian",
				"lingjiu-xinfa",
				"zhougong-jian",
			}),
		"Ľ������":({
				"zihui-xinfa",
				"douzhuan-xingyi",
				"beidou-xianzong",
				"canhe-zhi",
				"qixing-quan",
				"murong-sword",
				"longcheng-shendao",
			}),
		"ŷ������":({
				"shedu-qiqiao",
				"hamagong",
				"chanchu-bufa",
				"lingshe-quan",
				"lingshe-zhangfa",
				"baibian-daxue",
			}),
		"�������":({
				"lengyue-shengong",
				"hujia-daofa",
				"taxue-wuhen",
				"sixiang-bufa",
				"mantian-xing",
				"tianchang-zhang",
				"hujia-quan",
				"baisheng-daofa",
				"miaojia-jian"
			}),
		"���ϻ���":({
				"duanshi-xinfa",
				"tiannan-step",
				"jinyu-quan",
				"duanjia-sword",
				"sun-finger",
				"wuluo-zhang",
				"feifeng-whip",
				"qingliang-daxuefa",
				"yuezhao-gong",
			}),
	]);

	me = this_player();

	if(me->query("wujue_skill"))
	{
		tell_object(me,"���Ѿ�ʹ�ù�һ����������ˣ�ÿ����ֻ��ʹ��һ�Σ�\n");
		return 1;
	}

	if(me->query("combat_exp")<600000)
	{
		tell_object(me,"��Ϊ����60�򣬲���ʹ��������ƣ�\n");
		return 1;
	}

	if(!arg)
	{
		fams = keys(all_fam);
		str = ZJOBLONG"��ѡ������ϲ�������ɣ�\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		for(i=0;i<sizeof(fams);i++)
		{
			str += fams[i]+":taojiao "+fams[i];
			if(i<(sizeof(fams)-1)) str += ZJSEP;
		}
		tell_object(me,str + "\n");
		return 1;
	}

	if(sscanf(arg,"%s %s",family,skill)!=2)
	{
		if(!all_fam[arg])
		{
			tell_object(me,"û��������ɣ�\n");
			return 1;
		}

		if(me->query("family/family_name") == arg)
		{
			tell_object(me,"���Լ������ɣ�������ô�鷳��\n");
			return 1;
		}

		skills = all_fam[arg];
		str = ZJOBLONG"��ѡ������ϲ����["+arg+"]���ܣ�\n"ZJOBACTS2+ZJMENUF(2,2,10,30);
		for(i=0;i<sizeof(skills);i++)
		{
			str += to_chinese(skills[i])+ZJBR+skills[i]+":taojiao "+arg+" "+skills[i];
			if(i<(sizeof(skills)-1)) str += ZJSEP;
		}
		tell_object(me,str + "\n");
		return 1;
	}

	if(!all_fam[family])
	{
		tell_object(me,"û��������ɣ�\n");
		return 1;
	}

	if(member_array(skill,all_fam[family])==-1)
	{
		tell_object(me,family+"û����Ҫ��������ܣ�\n");
		return 1;
	}

	if(file_size(SKILL_D(skill)+".c")<0)
	{
		tell_object(me,"û��������ܣ�\n");
		return 1;
	}

	if (me->query_skill(skill,1))
	{
		tell_object(me,"���Ѿ�������������ˣ������ٴ�ѧϰ��\n");
		return 1;
	}

	if (!SKILL_D(skill)->valid_learn(me))
	{
		tell_object(me,"��Ŀǰ���������������մ���ܣ�("+skill+")\n");
		return 1;
	}

	mskills = me->query_skills();

	if (SKILL_D(skill)->valid_enable("force") && !SKILL_D(skill)->valid_force("*"))
	foreach (skill_name in keys(mskills))
	{
		if (! SKILL_D(skill_name)->valid_enable("force"))
			continue;

		if (! SKILL_D(skill_name)->valid_force(skill))
		{
			tell_object(me,"�㲻ɢ��" + to_chinese(skill_name) + "����ôѧϰ" + to_chinese(skill) + "��\n");
			return 1;
		}
	}

	me->set_skill(skill,180);
	me->set("wujue_skill",skill);
	tell_object(me,"��������180��" + to_chinese(skill) + "��\n");
	log_ufile(me,"wujueling","ʹ���������������180��" + to_chinese(skill) + "��\n");

	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }