#include <ansi.h>
inherit COMBINED_ITEM;


string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
	set_name(HIW "ϴ�ĵ�" NOR, ({ "xixin dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����Ө��͸�ĵ�ҩ������֮��ʹ��ǿ��ɢȥ�����书���Ӷ����°�ʦѧ��("HIR"ע�⣺һ��ʹ�ý���������Ѿ���̵ľ�ѧ"NOR")��\n");
		set("unit", "��");
		set("value", 50000);
		set("jifeng", 2000);
	    set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);		
		set("only_do_effect", 1);
		set("weight", 1);
		set("base_weight", 200);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;
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
				"yijinjing",//������180
				"yizhi-chan",
				"zui-gun",
//����Ϊ���ֲؾ��������书
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
			//	"lonely-sword",
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
				"jiuyin-baiguzhao",//����������Ϊ�������ܿ�ѧ��100��
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
				//"count",
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
				"dragon-strike",//������ѧ���賴��
				"jiaohua-bangfa",
				"dagou-bang",
				"mantianhuayu-zhen",
				"jueming-tui",
				"chansi-shou",//������
				"suohou-gong",//���Ԫ
				"fengmo-zhang",//���о�
				"fumo-zhang",//jian
				
			}),
		"��Ĺ��":({
				"yunv-xinfa",
				"surge-force",
				"yunv-jian",
				"quanzhen-jian",
				"xuantie-jian",
				"yunv-shenfa",
				"meinv-quan",
				"sad-strike",//����
				"fireice-strike",
				"tianluo-diwang",
				"yufeng-zhen",
				"yinsuo-jinling",
				"tianluo-diwang",
				"zuoyou-hubo",
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
				//"zuoyou-hubo",
				"kongming-quan",
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
				"feifeng-whip",//���׷�
				"qingliang-daxuefa",//�쵤��
				"yuezhao-gong",//hua
				"six-finger",
			}),
		"����":({
				"qiankun-danuoyi",
				"shenghuo-xinfa",
				"shenghuo-quan",
				"guangming-zhang",
				"liehuo-jian",
				"qingfu-shenfa",
				"hannbing-mianzhang",
				"yinfeng-dao",
				"tougu-zhen",
				"sougu-yingzhua",
				"qishang-quan",
				"pili-quan",
				"shenghuo-shengong",
				"taiji-quan",
				"taiji-jian",
				"jiuyang-shengong",
			}),
		"�������":({
				"riyue-xinfa",
				"liushui-bian",
				"tianmo-gun",
				"xuwu-piaomiao",
				"tianmo-zhang",
				"tianmo-dao",
				"tianmo-jian",
				"pili-daofa",
				"huanmo-longtianwu",
				"xixing-dafa",
				"riyue-guanghua",
				"kuihua-shengong",
			}),
				"�ƻ���":({
				"jueqing-zhang",
				"mingyu-shengong",
				"mingyu-gong",
				"yihua-jiemu",
				"yifeng-jian",
				"yifeng-dodge",
				"riyue-xinfa",						
			}),
			"ħ��":({
				"moshen-xinfa",
				"moshen-bufa",
				"moshen-quanfa",
				"liuxing-jianfa",
				"moshen-daofa",
				"moshen-zhangfa",
				"moshen-jianfa",
				"yinlong-shou",
				"chiyou-kuangzhanjue",
				"jiutian-xiaoyaobu",
				"mingyue-blade",
				"moon-blade",
				"yanzi-blade",
				"nuquan",
				"longteng-daofa",
				
			}),
			"���Ƴ�":({
				"feixian-sword",
				"jingyiforce",
				"feixian-steps",
				"feixian-jian",
										
			}),
			"��ɽ��":({
				"shushan-force",
				"zuixian-steps",
				"xianfeng-spells",
				"fumozhang",
				"songhe-sword",
										
			}),
			"�����":({
				"jueqing-xinfa",
				"jueqing-shenfa",
				"guhong-zhang",
				"guxing-jian",
				"luoyun-dao",
				"poshui-zhang",
				"fenxin-jue",
				"pokong-quan",
				"jueqing-zhang",
				"yinyang-ren",
				"zilei-jian",
				"tianjue-dao",
				"poguang-dao",
				"jueqing-jian",
				"tiezhang-xinfa",
				"tianlei-shengong",
				"dengping-dushui",
				"tiexian-quan",
				"chuanxin-zhang",
				"feilong-zhang",
				"tie-zhang",
			}),
			"佻�����":({
				"huanhua-jian",
				"guiyuan-dafa",
				"tiexian-quan",
				"feihua-wuping",
			}),
			  "��ڤ��":({
				"xuanming-shengong",
				"lingxu-bu",
				"piaofeng-quan",
				"feihua-zhang",
				"xuanming-zhang",
				"dulong-shenzhua",
				"hexing-bifa",
				"pili-daofa",
            }),		
		"��������":({
				"feixian-sword",
				"jingyiforce",
				"feixian-steps",
				"feixian-jian",
										
			}),
	]);

	if(!me->query("family"))
	{
		tell_object(me,"�㻹û��ʦ�Űɣ�����ʹ��"+query("name")+"��\n");
		return 0;
	}
	message_vision(CYN "$N" CYN "С�ĵķ�����һ"+query("unit")+"" + name() + CYN "�������������ˡ�"NOR"\n", me);

	family = me->query("family/family_name");
	if(skills=all_fam[family])
	{
		for(i=0;i<sizeof(skills);i++)
		{
			if(skills[i] == "count")
			{
				if(me->query_skill(skills[i],1)>380)
					me->set_skill("count",380);
			}
			else
				me->delete_skill(skills[i]);
		}
	}
	else
	{
		tell_object(me,"�������ݴ�������ϵ����Ա��\n");
		return 0;
	}
	CHANNEL_D->do_channel( this_object(), "rumor","��˵"+me->query("name")+"������һ��"+this_object()->query("name")+""HIM"�������һ������ѡ��ʦ�ŵĻ��ᣡ");
	me->delete("can_perform");
	me->delete("family");
	me->delete("title");
	me->delete("class");
	//��鼼���Ƿ����Ҫ�󣬲����ϵ�ɾ��
	UPDATE_D->check_skill(me);
	add_amount(-1);

	return 1;
}
