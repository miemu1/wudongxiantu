// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob;
        int count,mengxin;
        string a;
		me = this_player();
	me->set_skill("badao", me->query_skill("badao",1) + 9999);
	me->set_skill("liangyi-yinyangjue", me->query_skill("liangyi-yinyangjue",1) + 9999);
	me->set_skill("wushang-jianjing", me->query_skill("wushang-jianjing",1) + 9999);
	me->set_skill("lunhui-sword", me->query_skill("lunhui-sword",1) + 9999);
    me->set_skill("taiyan-dijing", me->query_skill("taiyan-dijing",1) + 9999);
	me->set_skill("yinyangjiuzhuanshierchongtian", me->query_skill("yinyangjiuzhuanshierchongtian",1) + 9999);
    me->set_skill("martial-cognize", me->query_skill("martial-cognize",1) + 9999);
	me->set_skill("lianyu-mojing", me->query_skill("lianyu-mojing",1) + 9999);
	me->set_skill("longwang-shengjing", me->query_skill("longwang-shengjing",1) + 100);
    me->set_skill("douzhan-shengjing", me->query_skill("douzhan-shengjing",1) + 9999);
    me->set_skill("never-defeated", me->query_skill("never-defeated",1) + 9999);
    me->set_skill("jiuyin-shengong", me->query_skill("jiuyin-shengong",1) + 9999);
    me->set_skill("kuihua-mogong", me->query_skill("kuihua-mogong",1) + 9999);
    me->set_skill("bluesea-force", me->query_skill("bluesea-force",1) + 9999);
    me->set_skill("shanggu-mijing", me->query_skill("shanggu-mijing",1) + 9999);
	me->set_skill("tianrenheyi", me->query_skill("tianrenheyi",1) + 9999);
	me->set_skill("wanmo-futi", me->query_skill("wanmo-futi",1) + 9999);
	me->set_skill("buddhism", me->query_skill("buddhism",1) + 9999);
	me->set_skill("force", me->query_skill("force",1) + 9999);
	me->set_skill("dodge", me->query_skill("dodge",1) + 9999);
	me->set_skill("unarmed", me->query_skill("unarmed",1) + 9999);
	me->set_skill("cuff", me->query_skill("cuff",1) + 9999);
	me->set_skill("strike", me->query_skill("strike",1) + 9999);
	me->set_skill("finger", me->query_skill("finger",1) + 9999);
	me->set_skill("hand", me->query_skill("hand",1) + 9999);
	me->set_skill("claw", me->query_skill("claw",1) + 9999);
	me->set_skill("sword", me->query_skill("sword",1) + 9999);
	me->set_skill("blade", me->query_skill("blade",1) + 9999);
	me->set_skill("staff", me->query_skill("staff",1) + 9999);
	me->set_skill("hammer", me->query_skill("hammer",1) + 9999);
	me->set_skill("club", me->query_skill("club",1) + 9999);
	me->set_skill("whip", me->query_skill("whip",1) + 9999);
	me->set_skill("parry", me->query_skill("parry",1) + 9999);

me->add("dajif",10000000);
me->add("balance",1000000000000);
me->add("yuanbao",100000000);
me->add("tianji1",100000000);
me->add("jifeng",100000000);
me->add("potential",10000000000);

	me->add("str",999);
	me->add("int",999);
	me->add("con",999);
	me->add("dex",999);
	me->add("per",999);
	me->add("kar",999);
	me->add("max_neili",10000000);
	me->add("max_jingli",10000000);
	me->add("max_jing",10000000);
	me->add("max_qi",10000000);
	me->add("gain/damage",1000);
	me->add("gain/2ap",1000);
	me->add("gain/2dp",1000);
	me->add("gain/break",1000);
	me->add("gain/armor",1000);
	me->add("max_food",1000);
	me->add("max_water",1000);
	me->add("combat_exp",100000000000);
	
	ob = new("clone/GMwupin/GMSSS11");
    ob->set_amount(1);
	ob->move(me);
	write("成功激活GM特权!您的账号已变成GM账号!\n");
        tell_object(me,HIW"你获得了：\n" +
        999 + "根骨。\n"+
        999 + "膂力。\n"+
        999 + "悟性。\n"+
        999 + "身法。\n"+
        999 + "容貌。\n"+
        999 + "福源。\n"+
        10000000 + "内力上限。\n"+
        10000000 + "精力上限。\n"+
        10000000 + "精神上限。\n"+
        10000000 + "气血上限。\n"+
        10000000 + "饥饿上限。\n"+
        10000000 + "水分上限。\n"+
        1000 + "基础伤害。\n"+
        1000 + "暴击值。\n"+
        1000 + "抗暴值。\n"+
        1000 + "护甲值。\n"+
        1000 + "破甲值。\n"+
        9999 + "【开天仙经】等级\n" +
        9999 + "【阴阳道经】等级\n" +
        9999 + "【六道仙经】等级\n" +
        9999 + "【太始帝经】等级\n" +
        9999 + "【归真道经】等级\n" +
        9999 + "【太元帝经】等级\n" +
        9999 + "【无上剑经】等级\n" +
        9999 + "【太衍帝经】等级\n" +
        9999 + "【上古秘经】等级\n" +
        9999 + "【基础技能】等级\n" +
		9999 + "【炼狱魔经】等级\n" +
		9999 + "【斗战圣经】等级\n" +
		9999 + "【武学修养】等级\n" +
        9999 + "【禅宗心法】等级\n" +
        9999 + "【不败神功】等级\n" +
        9999 + "【葵花魔功】等级\n" +
        9999 + "【南海玄功】等级\n" +
		9999 + "【龙王圣经】等级\n" +
        9999 + "【九阴神功】等级\n" +
        1000 + "亿修为\n" +
		100 + "万潜能\n" +		
        10 + "万黄金\n" +		
        10 + "万钻石\n" +		
        10 + "万灵石\n" +		
		10 + "万点券\n" +
        10 + "万天机\n" +		
		1 + "颗 八龙飞仙丹\n" +
        NOR);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家红包。
HELP
        );
        return 1;
}
