//inventory.c

#include <ansi.h>
inherit F_CLEAN_UP;
#include <command.h>
#include <config.h>

inherit F_DBASE;

void create() 
{
	seteuid(getuid());
	set("name", "老魔问答");
	set("id", "huida");
	set("channel_id", "老魔");
}
int main(object me,string arg)
{
	
string a,b,c;
object ob;
object *players;
int i,q=0,w=0,e=0,j,k,l;
       if(me->query("wenda")!=1)
		{
		tell_object(me,HIY"你不能再回答了！"NOR"\n"); 
		return 1;  
	   }
       if(!arg)
	   {
		tell_object(me,HIY"回答啥？"NOR"\n"); 
		return 1;  
	   }
       if(sscanf(arg, "%s %s %s",a,b,c)!=3)
	   {
	  	write(INPUTTXT("请输入内容：""","wenda $txt# "+arg)+"\n"); 
		return 1;
	   }
	    sscanf(arg, "%s %s %s",a,b,c);
		if(c!="1497163455!")
		{
		tell_object(me,HIY"想干啥？"NOR"\n"); 
		return 1;  
	   }
		 if(a==b)
		 {
		players = users();
		for(i = 0; i<sizeof(players); i++)
         {
			 if(players[i]->query("wenda")==2)
               q=1;
		   else if(players[i]->query("wenda")==3)
			   w=1;
		   else if(players[i]->query("wenda")==4)
			   e=1;
       }
	   if(q==0)
	   {
		   j=50000+random(1000);
		   k=50000+random(500);
		me->set("wenda",2);
		me->add("yuanbao",350);
		me->add("hdcs",1); 
		me->add("potential",j);
		me->add("combat_exp",k);
		me->add("dajif",100);
CHANNEL_D->do_channel(this_object(), "chat", HIR""HIC+me->query("name")+HIG"第一个抢答出来！"NOR"");
		tell_object(me,HIY"由于你是第一个回答出来，你获得了350灵石,"+j+"点潜能,"+k+"点修为，100颗钻石。"NOR"\n");   
	   }else if(w==0)
	   {
		j=35000+random(888);
		k=35000+random(500);
		me->set("wenda",3);
		me->add("yuanbao",250);
		me->add("hdcs",1); 
		me->add("dajif",50);
CHANNEL_D->do_channel(this_object(), "chat", HIR""HIC+me->query("name")+HIG"第二个抢答出来！"NOR"");
		tell_object(me,HIY"由于你是第二个回答出来，你获得了250灵石,"+j+"点潜能,"+k+"点修为，50颗钻石。"NOR"\n");  
	   }else if(e==0)
	   {
		   j=15000+random(500);
		   k=15000+random(500);
		me->set("wenda",4);
		me->add("yuanbao",150);
		me->add("hdcs",1); 
		me->add("dajif",35);
CHANNEL_D->do_channel(this_object(), "chat", HIR""HIC+me->query("name")+HIG"第三个抢答出来！"NOR"");
		tell_object(me,HIY"由于你是第三个回答出来，你获得了150灵石,"+j+"点潜能,"+k+"点修为，35颗钻石。"NOR"\n");  
	   }
	   else
	   {
		me->set("wenda",5);
		me->add("yuanbao",85);
		me->add("hdcs",1); 
		tell_object(me,HIY"你获得了50灵石的安慰奖"NOR"\n"); 
	   }
		return 1;
		 }
		 else 
		 {
		tell_object(me,HIY"可惜，你回答错了！"NOR"\n"); 
		me->set("wenda",0);
		return 1; 
		 }

}
int help (object me)
{
	tell_object(me,HIY"你对说道：“”。"NOR"\n");  
	return 1;
}