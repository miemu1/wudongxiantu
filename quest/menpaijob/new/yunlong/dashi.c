//snowman 28/02/98
#include <ansi.h>
inherit NPC;
string ask_huijia();
string ask_daojia();
int ask_rob();
void create()
{
	set_name(HIM"义士"NOR, ({ "yi shi", "yi", "shi" }) );
	set("gender", "男性" );
	set("age", 22+random(20));
	set("long",
		"这位志在反清复明的义士。\n");
        set("per", 35);
        set("no_get", 1);
        set("str", 40);
        set("int", 47);
        set("con", 46);
        set("dex", 48);
        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 4600);
        set("max_jing", 4600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("chat_chance", 0);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("inquiry", ([
        "护送" : (:ask_huijia:) ,
        "到了" : (:ask_daojia:) ,
         ]) );
        set("env/wimpy", 40);
        set_temp("apply/attack", 300);
        set_temp("apply/defense",300);
        set_temp("apply/armor", 300);
        set_temp("apply/damage", 100);
        setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}

void init()
{
        object ob = this_object();
	add_action("do_guard", "guard");
	this_player()->start_busy(1);
if (ob->query("lingsong") == 0 )
{
        remove_call_out("leave");
        call_out("leave",240);
}
}

void leave()
{
        object ob = this_object();
        if (ob->query("lingsong") == 0) {
                message_vision(HIG "反清义士见无人来接应,自己离开了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

string ask_huijia()
{
object me=this_player();
object ob = this_object();
if(me->query("kill_yunlong") == 0 )
return "我看你是清狗派来的那奸细吧。。。\n";
set_leader(me);
ob->set("lingsong",10);
return "地振高冈，一派溪山千古秀,反清义士和你对上了喑号.\n";
}

string ask_daojia()
{
 object ob,me;
// int exp,pot,base_exp
 ob = this_object();
me = this_player();
if(me->query("kill_yunlong") == 0 )
return "我看你是清狗派来的那奸细吧。。。\n";
 if( environment(ob)->query("short")=="春来茶馆")
         {

          set_leader(0);
          write("门朝大海，三河合水万年流.喑号对上了，\n");

             me->add("potential",200+random(400));
             me->add("combat_exp",300+random(600));
             me->set("kill_yunlong",0);
         write("你的修为和潜能提高了!!\n");
        call_out("leavet",1);
           return "我走了，大家保重.....\n";  
      }
        else {
                return "还没到呢!你想不管了吗?\n";
        }
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"，你现在不能用guard！\n");
        return 1;
}

void leavet()
{
        object ob = this_object();
        destruct(this_object());
}

void unconcious()
{            
	::die();       
}	