// daya.c 
//大雅剑法秘籍
//by dream @TXWX 2006.8.27 YC

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
void create()
{
        set_name(HIR"「大雅古剑」"NOR, ({ "daya book1","book1", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set("no_put", "这样东西不能放在那儿。\n");
                set("long",
        "这是一本书皮发黄的破旧古本。上书：「大雅古剑法 上册」。\n"
        "看来已经保存很久了。\n", );
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int pxlevel; 
	int neili_lost;

	if (!(arg=="daya book1" || arg == "book1"))
	return 0;
        if (where->query("pigging")){
                write("你还是专心拱猪吧！\n");
                return 1;
        }
        if (me->is_busy()) {
                write("你现在正忙着呢。\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("你无法在战斗中专心下来研读新知！\n");
                return 1;
        }
        if (!id(arg)) {	
                write("你要读什么？\n");
                return 1;
        }
        if( !me->query_skill("literate", 1) ){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }
        message("vision", me->name() + "正在研读大雅古剑秘籍.\n", environment(me), me);
        if( (int)me->query("jing") < 500 ) {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }
	neili_lost = 5;
        if( (int)me->query("neili") < neili_lost) {
		write("你内力不够，无法钻研这么高深的武功。\n");
                return 1;
        }
        pxlevel = me->query_skill("daya-jian", 1);
        if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel*500) {
                write("你的实战修为不足，再怎么读也没用。\n");
                return 1;
        }
        if( me->query_skill("daya-jian", 1) > 99){
                write("你研读了一会儿，但是发现上面所说的对你\n"
                       "而言都太浅了，没有学到任何东西。\n"
                        "要更进一步只有等待机缘拿到下册了.\n");
                return 1;
        }
        if( me->query("int", 1) < 30){
                write(HIR"你的悟性不够,你还不能学习这么高深的武功,\n"
                          "还是去多吃几朵雪莲再来吧!\n"NOR);
                return 1;
        }
        if( me->query("age", 1) < 36){
                write(HIR"你太年轻了,不能学习这么厉害的武功..\n"NOR);
                return 1;
        }
        if((int)me->query("kill/japan")<1)
        {
                write(HIR"你的秘籍怎么来的?偷来的?\n"NOR);
                return 1;
        }
        me->receive_damage("jing", 500);
	me->set("neili",(int)me->query("neili")-neili_lost);
        me->improve_skill("daya-jian", (int)me->query_skill("literate", 1)/3+1)
;
        write("你研读残酷大雅剑法，颇有心得。\n");
        return 1;
        
}

