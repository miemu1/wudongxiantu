//MUD强奸命令1.1版
//编程  四川工业大学  剑啸九天(sword)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj, old_target;
	int n;
	
//     if( environment(me)->query("no_fight") )
       //         return notify_fail(HIW" 光天化日之下怎可行淫.\n\n"NOR);
         if (wiz_level(me) < 3)
                return notify_fail(HIY" 东西还没长齐想干嘛？\n"NOR);
        if( (int)me->query("age") <= 10)
                return notify_fail(HIY" 东西还没长齐想干嘛？\n"NOR);

        if( me->query("combat_exp") <= 500000)
                return notify_fail(HIY" 你的修为这么低，还是练练高吧!\n"NOR);

        if( !wizardp(me)) 
	  return 0;
   //     if (!me->query("family/family_name"))
      //          return notify_fail(HIR"你无门无派，不是江湖中人!\n"NOR);

        if (me->is_busy()) 
                return notify_fail(CYN"你现在正忙着呢！还想干嘛？\n"NOR);

        if (!wizardp(me) )
                return notify_fail("你不是巫师，这个...就免了吧！\n");

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail(CYN" 你想非礼谁？\n"NOR);

        if(!obj->is_character() )
                return notify_fail(CYN" 看清楚一点，那并不是生物。\n"NOR);

        if((string)obj->query("race") == "野兽")
          return notify_fail(CYN" 搞什么？它又不是人！\n"NOR);

   //     if(obj==me)     return notify_fail(HIW" 强奸自己? 没听说过！\n"NOR);

   //     if((string)obj->query("gender") == "女性")
    //      return notify_fail(CYN" 搞同性恋可不行！\n"NOR);


        if((string)obj->query("gender") == "无性")
          return notify_fail(CYN" 他是阴阳人,乱搞什么嘛!\n"NOR);
        if( !living(obj) )
          return notify_fail("  \n");
        if( me->is_fighting() )
                return notify_fail(HIR"\n专心打架吧！！\n"NOR);

    ///if( userp(obj) && me->query_condition("killer"))
    //    return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
   // if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
   //     return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
 
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");

        if((int)obj->query("age") <= 1 && userp(obj))
                return notify_fail(CYN"她还是孩子，放过她吧！\n"NOR); 

        if( obj->query("env/no_fight") )
                return notify_fail(CYN"此人不允许下此指令！\n"NOR); 

        if(obj->query_temp("no_kill"))
                return notify_fail(CYN"此人不允许下此指令！\n"NOR); 


 else {             
                me->start_busy(2);
                obj->start_busy(2);
                message_vision(HIM"\n$N对著$n大叫一声：宝贝儿，老娘都哗啦啦了！\n说着便如狼似虎地向$n冲了过去！\n\n"NOR, me, obj);
                message_vision(HIC"$n对著$N大喝一声："+RANK_D->query_rude(me)+"你休想，看招！\n"NOR, me, obj);
                me->fight_ob(obj);
                obj->fight_ob(me);
                   //设定两者为敌对关系
                obj->remove_all_enemy(); //暂时停止，好让下面程序运行
                for(n=0;n<=random(6)+1;n++)
               {
                COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
                }
            if((int)me->query("qi") <= (int)me->query("max_qi")*3/4)
                call_out("do_leave",1,me,obj);
  else{        
                call_out("do_qiangjian", 2, me, obj); 
                call_out("do_look", 6, me, obj);
                call_out("do_look1", 8, me, obj);

       if((int)obj->query("per") > 22){                //考虑到差异，所以这里要分支
                call_out("do_qiangjian1", 14, me, obj);
                call_out("do_qiangjian2", 18, me, obj);
                call_out("do_qiangjian3", 22, me, obj);
                call_out("do_qiangjian4", 26, me, obj); //惩罚函数调用
                call_out("do_qiangjian5", 32, me, obj);
                call_out("do_qiangjian6", 38, me, obj);  //倒
                call_out("do_qiangjian7", 49, me, obj);
                call_out("do_qiangjian8", 61, me, obj);
                call_out("do_qiangjian9", 62, me, obj);

                call_out("do_wakeup",70,me,obj);
                call_out("do_kill",71,me,obj);  
  }   else{
        if((int)obj->query("per") > 17){   
                call_out("do_qiangjian2", 14, me, obj);
                call_out("do_qiangjian4", 19, me, obj); 
                call_out("do_qiangjian6", 25, me, obj);                
                call_out("do_qiangjian7", 31, me, obj);
                call_out("do_qiangjian10", 45, me, obj);
                call_out("do_qiangjian9", 47, me, obj);
                call_out("do_wakeup",57,me,obj);
                call_out("do_kill",58,me,obj);
                                
   }else{
                call_out("do_puke",11,me,obj);      
         }   
      }
      }        
      }
        return 1;   
}

void do_leave(object me,object obj)
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
        if(objectp(present(obj,environment(me)))){
        tell_object(me,HIY"\n看来"+(string)obj->query("name")+"不好惹，你决定还是打消念头，走开为好！\n"NOR, me, obj); 
        tell_object(obj,HIY"\n看来你的武功已让"+(string)obj->query("name")+"心生怯意了.他边打边退，似乎想逃!"NOR);
        me->set("wimpy",100);
        me->start_busy(1);
        call_out("do_hit",0,me,obj);
        call_out("do_setwimpy",5,me,obj);
 }    return;
}

void do_hit(object me, object obj)
{
        if(objectp(present(obj,environment(me)))){
      message_vision(HIC"\n$n对着$N大喝一声:"+RANK_D->query_rude(me)+"，想走? 没门！尝尝本"+RANK_D->query_respect(obj)+"厉害再说！\n"NOR,me, obj);   
                COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
                COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
                me->fight_ob(obj);
                obj->fight_ob(me);
//                me->move(random(sizeof(keys(environment(me)->query("exits")))));
  }
        return;
}
void do_setwimpy(object me,object obj)
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");

                me->set("wimpy",20);
        return;
}
           
void do_qiangjian(object me, object obj)
{
        mapping my_family;
        string my_fam;
        my_family = me->query("family"); 
        my_fam = my_family["family_name"];
        if(objectp(present(obj, environment(me)))) {
                me->start_busy(100);
                obj->start_busy(100);
        if( !living(obj) )
        message_vision(CYN"\n$N对着昏倒在地的$n笑道:昏了？，这可如何是好!如何插入-\n$N缓步来到$n身前，扶起$n的躯体。\n"NOR, me, obj); 
       else{
        message_vision(HIM"\n$N脱了衣服露出私处对着$n死命晃悠,$n大喊老子受不了啦小娘皮.\n\n"NOR, me, obj);
        tell_object(me,HIY"看来他被你深深吸引，已经血脉喷张，你感觉下面快要发洪水了！\n"NOR);               

        tell_object(obj,HIY"\n你还想作拼死反抗。\n但是下体已经快胀死了,还是好好享受吧。\n\n"NOR);
               obj->set_temp("block_msg/all", 1);  
               environment(obj)->add_temp("no_fight",1);
               environment(obj)->add_temp("sleeping_person", 1);
               obj->set("hunmi",1);
           }  
	       CHANNEL_D->do_channel(this_object(), "rumor",
	       sprintf("我看见%s的%s正在干坏事!!!!!!!", my_fam, me->name(1))); 
                                                  }     //为pksex埋下伏笔
           return;
}

void do_look(object me,object obj)
{     
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("\n由于近在咫尺，$N又忍不住仔细端详了$n一下\n", me, obj);
                                                   }
           return;
}
void do_look1(object me,object obj)
{     
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
        if(objectp(present(obj, environment(me)))) {
   tell_object(me,HIM"\n你望了望附近，看了看，没人注意你，不由的.....\n"NOR);
                                                   }
           return;
}

void do_puke(object me, object obj)
{
     if(objectp(present(obj, environment(me)))) {
        message_vision(CYN"\n$N稀里哇啦地吐了一地。\n"NOR, me,obj);
        tell_object(me,HIY"你不由得对自己说：天啦，这世上还有这么丑的男人，我还是站远些好！\n"NOR);    
        message_vision("\n$N远远地推开$n,苦笑着说："+RANK_D->query_respect(obj)+"，如此‘尊容’，在下实在干涩无比\n还不如老王家养的大黄！\n",me,obj); 
        message_vision(CYN"\n$N去菜市场买黄瓜去了。\n"NOR,me,obj);
        me->start_busy(1);
        obj->start_busy(1);
}
         return;
}

void do_qiangjian1(object me,object obj)  
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("接着，$n的大手不顾$N的挣扎在$n的身上来回上下游走.......\n", me, obj);   

}

        return;
}
void do_qiangjian2(object me,object obj)  
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("\n好一会儿,$n再也按赖不住心中的欲火，将$N身上的衣物一件一件地扯下\n", me, obj);

}

        return;
}
void do_qiangjian3(object me,object obj)  
{
         //if (!me)  return notify_fail("你已经断线了！\n");
        // if (!obj)  return notify_fail("那个人已经不在了！\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("\n经过一番撕扯，$N的衣物已经七零八落地散落地上，身上只剩\n", me, obj);
        message_vision("件肚兜遮羞，光滑柔嫩的肩背展现在$N的眼前！真是风景无限！\n", me, obj);
        if((int)obj->query("per") >= 30){
        message_vision("\n只见$n浑身肌肤雪白，晶莹剔透,婉如玉人。\n",me,obj);}
 }
     return;
}

void do_qiangjian4(object me,object obj)       //为了增加随机性,以年龄和容貌为指标
                                               //建立此函数,由于编者是站在正义这方的
                                               //所以此函数是用来惩罚命令使用者的
{      
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
         if(objectp(present(obj, environment(me)))) {


         if((int)obj->query("combat_exp") <= 5000) {
           me->add("combat_exp", -(int)obj->query("combat_exp")/30);        
         }else{
           me->add("combat_exp", -(int)obj->query("combat_exp")/50);
              }
           me->add("shen",-random(1000));   
                                                       
                                          }
                                          
else{
        if((int)obj->query("age") <= 30 ) {

         message_vision(HIM"\n虽说已不再是处女,但身为少妇的$n那丰满的身体曲线也让$N垂涎三尺!\n"NOR, me, obj);
           me->add("shen",-random(5000));   
         if((int)obj->query("combat_exp") <= 5000) {
           me->add("combat_exp", -(int)obj->query("combat_exp")/30);
//           me->add("potential", -random((int)me->query("potential")/4));       
         }else{
           me->add("combat_exp", -(int)obj->query("combat_exp")/50);
              }

         }else{ 
           if((int)obj->query("age") >= 55 ) {
         message_vision(HIM"\n看来$N已经饥渴到饥不择食的地步了,连$n这样的老大爷也不放过!\n"NOR, me, obj);
         message_vision(HIW"\n小心招天谴!!!\n"NOR, me, obj);
           me->add("shen",-random(5000)-5000);   
         if((int)obj->query("combat_exp") <= 5000) {
           me->set("combat_exp",random((int)me->query("combat_exp")/4));    //惩罚乱用此命令者
         }else{
           me->add("combat_exp", -random((int)me->query("combat_exp")/15));
              }
         }else{
         message_vision(HIM"\n$n虽已是中年迟暮,但虎威仍在仍让$N大感刺激!\n"NOR, me, obj); 
           me->add("shen",-random(5000));   
         if((int)obj->query("combat_exp") <= 5000) {
           me->add("combat_exp", -random((int)me->query("combat_exp")/10));
         }else{
           me->add("combat_exp", -random((int)me->query("combat_exp")/20));
                                                 
              }
              }
              }
     }
                                                   }

void do_qiangjian5(object me,object obj)  
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision("\n$n大手一挥，$N身上仅剩的肚兜也落下地了！这一下温香满怀，\n", me, obj);
        message_vision("$N对$n说你的大棒子让人家好爽哦！\n", me, obj);
}

        return;
}
void do_qiangjian6(object me,object obj)  
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");

        if(objectp(present(obj, environment(me)))) {
        message_vision(HIM"\n接着$n一把将$N按倒在地上。。。。。\n"NOR, me, obj);

}

        return;
}
void do_qiangjian7(object me,object obj)  
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");

        if(objectp(present(obj, environment(me)))) {
        message_vision("\n。。。。。。。。。。\n"NOR, me, obj);
        message_vision("。。。四周充斥着$n那野兽般的吼叫声和$N伊伊啊啊的呻吟。。。\n", me, obj);
}

        return;
}
void do_qiangjian8(object me,object obj)  
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");

        if(objectp(present(obj, environment(me)))) {
        message_vision(HIM"\n良久，风停雨歇。。。。\n"NOR, me, obj);
        message_vision("$N挣扎着爬了起来，对着精尽人亡的$n满足地淫笑了一下。\n", me, obj);

}
        return;
}
void do_qiangjian9(object me,object obj)  
{	
        mapping my_family;
        string my_fam;
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
        my_family = me->query("family"); 
        my_fam = my_family["family_name"];	


        if(objectp(present(obj, environment(me)))) {
        message_vision(HIR"\n这时只见$N摇摇晃晃，立足不稳。\n"NOR, me,obj);
        tell_object(me,HIR"\n原来你发现自己全身乏力，看来是被折腾得不轻！\n\n"NOR);
        me->set("qi",(int)obj->query("eff_qi")/2);

					CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s被%s的%s强奸了。",obj->name(1), my_fam,me->name(1)));
					CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s被官府通缉了。", me->name(1)));

        me->start_busy(1);
        me->apply_condition("killer", 180 +
			me->query_condition("killer"));
        me->apply_condition("sexman", 180 +
			me->query_condition("sexman"));
        me->add("PKS", 1);
}
        return;
}

void do_qiangjian10(object me,object obj)  
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");
        if(objectp(present(obj, environment(me)))) {
        message_vision(HIM"\n良久，风停雨歇。。。。\n"NOR, me, obj);
        message_vision("$N爬了起来，对着昏睡在地的$n失望地叹了一下气：真他妈的垃圾还不如隔壁大黄狗。\n", me, obj);
}
        return;
}
void do_wakeup(object me,object obj)
{
        // if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");

               obj->set("hunmi",0);            
               obj->set_temp("block_msg/all", 0);
	   if (!environment(obj)->query("sleep_room") && !environment(obj)->query("hotel"))
	       environment(obj)->set("no_fight",0);
     	       environment(obj)->add_temp("sleeping_person", -1);
               obj->set("qi",(int)obj->query("max_qi"));
               obj->set("jing",(int)obj->query("max_jing"));
               tell_object(obj,HIC"\n看来你的力气恢复得差不多了！\n"NOR);
               message_vision(HIY"\n$N慢慢地爬了起来！\n"NOR,obj);
               obj->start_busy(1);

        return;
}
void do_kill(object me,object obj)    
{
         //if (!me)  return notify_fail("你已经断线了！\n");
         //if (!obj)  return notify_fail("那个人已经不在了！\n");


     }




int help(object me)
{
  write(@HELP
指令格式 : qiangjian <人物>
   
   江湖中无风不起浪,武侠的世界里总是少不了采花贼的，
象金庸先生笔下的田伯光等,这个命令正是留给他们的.
但当采花贼不仅对修为不利,而且还要面对满街的讨打声，
没有一点真本事,可有点受不了。
   有道是'多行不义必自毙'，用之者慎之！慎之！
当然正人君子莫为之！
HELP
    );
    return 1;
}
