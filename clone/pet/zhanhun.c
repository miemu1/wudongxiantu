// by name
 
#include <ansi.h>
inherit NPC;
inherit F_SSERVER;
inherit F_SAVE;
int is_zhanhun(){ return 1; }
string query_save_file()
{
	string id;
	id = query("owner");
	if (! stringp(id))
	return 0;
	return sprintf(DATA_DIR "zhanhun/%c/%s", id[0], id);
}
void create()
{

	::create();
	set_name("战魂", ({ "zhanhun beast" }));
	set("race", "野兽");
	set("unit", "具"); 
	set("str", 50);
	set("int", 50);
	set("spi", 50);
	set("con", 50);
	set("dex", 50);
 	set("no_sell", "这玩意不能卖！"); 
    set("eff_qi", 10000);
	set("eff_jing", 10000);	
	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 10000);
	set("max_neili", 10000);    
	set("jingli", 10000);
	set("max_jingli", 1000);		 
	set("combat_exp", 10000);
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defence",100);
	set_temp("apply/armor", 100);
    set_temp("apply/unarmed_damage",100);
	setup();
	set_heart_beat(1); 
}
string long()
{
	string result;
    object ob=this_object();
	result = query("long");
	return result;
}
void heart_beat()
{
	object ob,me,emy;
	me = this_object();

	if (!present(me,ob)&&!present(me,environment(ob))){
		me->move(environment(ob));
		me->set_leader(ob);
	}
	
	::heart_beat();
}
void die()
{	
    int jing, qi;	
	jing = (int) query("max_jing");
	qi = (int) query("max_qi");
    set("eff_qi", qi);
	set("eff_jing", jing);
	set("qi", qi);
	set("jing", jing);
	save();	
	return ::die();
}
void unconcious()
{
	die();
}
