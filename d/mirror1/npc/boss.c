//edit by rock
//2008.10.20

#include <ansi.h>
inherit NPC;

#define PRODUCT "/clone/shoufei/product"
string *box_object=({
"clone/good/1/d1_arrmor",
"clone/good/1/d1_boots",
"clone/good/1/d1_cloth",
"clone/good/1/d1_finger",
"clone/good/1/d1_hands",
"clone/good/1/d1_head",
"clone/good/1/d1_neck",
"clone/good/1/d1_pants",
"clone/good/1/d1_shield",
"clone/good/1/d1_surcoat",
"clone/good/1/d1_waist",
"clone/good/1/d1_wrists",
});
void create()
{
	set_name("强盗头目", ({ "tou mu"}));
	set("title",HIR"烧光 杀光 抢光"NOR);
	set("gender", "男性");
	set("age",26);
	set("long", "他是一位强盗头目。\n");
	set("str", 330);
	set("int", 24);
	set("con", 330);
	set("dex", 324);

        set("qi", 10000000);
	set("max_qi", 10000000);
	set("jing", 10000000);
	set("max_jing", 10000000);
	set("neili", 10000000);
	set("max_neili", 10000000);
	set("jiali", 300);

	set("combat_exp", 90000000);
	set("score", 200000);
	set("shen", -100000);

		set_skill("fengmo-zhang",800+random(200));
	set_skill("liuhe-zhang",800+random(200));
	set_skill("strike",800+random(200));
	set_skill("force", 800+random(200));             // 基本内功
	set_skill("huntian-qigong", 800+random(200));    // 混天气功
	set_skill("unarmed", 800+random(200));           // 基本拳脚
	set_skill("xianglong-zhang", 800+random(200));   // 降龙十八掌
	set_skill("dodge", 800+random(200));      	     // 基本躲闪
	set_skill("xiaoyaoyou", 800+random(200));        // 逍遥游
	set_skill("parry", 800+random(200));             // 基本招架
	set_skill("staff", 800+random(200));             // 基本棍杖
	set_skill("dagou-bang", 800+random(200));        // 打狗棒法
	set_skill("begging", 800+random(200));           // 叫化绝活
	set_skill("checking", 800+random(200));          // 道听途说
	set_skill("training", 800+random(200));         // 驭兽术

	set_skill("yuejia-qiang", 800+random(200));        // 打狗棒法
	set_skill("suohou-gong", 800+random(200));        // 打狗棒法
	set_skill("chansi-shou", 800+random(200));        // 打狗棒法
	set_skill("claw", 800+random(200));        // 打狗棒法
	set_skill("hand", 800+random(200));        // 打狗棒法
	set_skill("club", 800+random(200));        // 打狗棒法

	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	map_skill("strike", "xianglong-zhang");
	map_skill("claw", "suohou-gong");
	map_skill("hand", "chansi-shou");
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),
                (: command("unwield lvyv bang") :),
                (: command("wield lvyv bang") :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.kanglongwuhui" :),
                (: perform_action, "unarmed.hui" :),
                (: perform_action, "unarmed.fei" :),
                (: perform_action, "unarmed.qu" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.leiting" :),
                (: perform_action, "unarmed.xianglong" :),
                (: perform_action, "dodge.gjtq" :),
                (: perform_action, "dodge.canghaiyixiao" :),
                (: perform_action, "dodge.maishou" :),
        }) );
	set_temp("apply/attack",300);
	set_temp("apply/defense",300);
	set_temp("apply/armor",3000);
	set_temp("apply/damage",2000);
	setup();
	carry_object("/clone/misc/baipao")->wear();
	carry_object("kungfu/class/gaibang/obj/yuzhu_zhang")->wield();
}

void init()
{
	call_out("findPlayer",5); //寻敌
}

void dest_world(object memory)
{
	if(!memory) return;
	memory->delete_map();
	destruct(this_object());
}

void die()
{
	object me,ob,memory,item;
	mapping team;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = ob->query_temp("last_damage_from");
	team = me->query_team();
	memory = (object)me->query_temp("mirror/mirror_memory");

	if(!team || !clonep(memory) || !team || !me || !userp(me))
	{
		memory = environment(ob)->query("memory");
		if(clonep(memory)) memory->delete_map();
		destruct(ob);
		return;
	}

	size = sizeof(team);
	for(i=0;i<size;i++)
	{
		if(!team[i]) continue;
		level = team[i]->query("level");
		exp = 50000 * size+random(50000)*2;

		if(exp)
		{
			pot = exp / 2;
			tell_object(team[i],sprintf("你获得了%d点修为，%d点潜能。\n",exp,pot));
			tell_object(team[i],HIY"【武动仙途】恭喜你挑战镜像成功！请拾取物品，镜像将在1分钟后关闭。\n"NOR);
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
			if (team[i]->query("zhuanshen"))
			{
				team[i]->add("yuanshen/exp",100+random(100));
			}

		}
	}

	//掉宝
    rand = random(100);

	if(rand < 10)
	{
		item = item = new(random(sizeof(box_object)));
		if(item)
		{
			item->move(environment(ob));
		}
	}
	memory->quest_over();
	destruct(ob);
}

//函数：寻敌
void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;

	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);

	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(5));
}
