#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit COMBINED_ITEM;

void create()
{
   if( clonep())  set_default_object(__FILE__);
   set_name(HIW"新年贺卡"NOR ,({"wish-card","card",}));
  set("long","一张漂亮的贺卡，应该可以写(modify)点什么在上面吧。\n");
  set("base_unit", "张");
    set("unit","叠");
    set("base_weigt",3);
     set("value",0);
     set_amount(1);
     set("no_put",1);
//     set("no_store",1);
    setup();
}

int init ()
{
     add_action ("do_post", "post");
    add_action  ("do_modify","modify");
    add_action ("do_change","dismodify");
    add_action("do_check","check");
  return 1;
}
int do_check(string arg)
{   object card = this_object(),me = this_player();
     string msg,title ;
    if (arg == "card"){
       title=read_file(__DIR__"xmas.msg",1);
       message_vision(HIW+title+NOR+"\n",me);
      if (card->query("post_msg")){
              msg  = this_object()->query("post_msg");
              message_vision(msg,this_player());
                                                } 
                       }
       else return notify_fail("格式：check card. \n");
   return 1;
}
    
int do_post (string arg)
{      
    object who,me,card;
       string msg,title;    
    if(!arg) return notify_fail("格式：post ID \n");
    if(!find_player(arg))  return notify_fail("没有这个人呀！\n");
      who = find_player(arg);me = this_player(); card = this_object();
       if (card->query("post_msg"))   msg = card->query("post_msg");
    
    message_vision(BLINK+HIY"  叮铃铃，$N送给$n的贺卡寄到了！！\n\n"NOR,me,who);
       title=read_file(__DIR__"xmas.msg",1);
       message_vision(HIW+title+NOR+"\n",me,who);
           if (card->query("post_msg")) message_vision(msg,me,who); 
//    destruct(card);
        add_amount(-1);
   return 1;
}

int do_change(string arg) 
 { if(!arg||arg!="card") return notify_fail("格式：dismodify card");
   if (this_object()->query("post_msg")) {
                     this_object()->delete("post_msg");
                     tell_object(this_player(),"你拿起橡皮，将原来写的擦除了！\n");
                                                                        }
   else return notify_fail("你以前并没有写(modify)祝福的话呀!\n");
//    call_out("do_modify",arg);
}

int do_modify( string arg)
{ object me=this_player(),card=this_object();
    if (!arg) 
  {   message_vision(@LONG
格式实例：modify 亲爱的XXX,祝你圣诞快乐!!
 
这个指令可以让你为寄给别人的贺卡写一句祝福的话，你如果希望在话中
使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

$BLK$ - 黑色            $NOR$ - 恢复正常颜色
$RED$ - 红色            $HIR$ - 亮红色
$GRN$ - 绿色            $HIG$ - 亮绿色
$YEL$ - 土黄色          $HIY$ - 黄色
$BLU$ - 深蓝色          $HIB$ - 蓝色
$MAG$ - 浅紫色          $HIM$ - 粉红色
$CYN$ - 蓝绿色          $HIC$ - 天青色
$WHT$ - 浅灰色          $HIW$ - 白色

写完后可以用check card指令查看效果,如不满意,可用dismodify擦除。
用post ID，可以将贺卡寄给别人。

LONG
,me);
        if (card->query("post_msg")) 
  { write("这张贺卡已经写好了,要重写就先擦除(dismodify card)吧!\n");
       return 1;
    }
}
        else if (arg)
  {   
      arg = replace_string(arg, "$BLK$", BLK);
      arg = replace_string(arg, "$RED$", RED);
      arg = replace_string(arg, "$GRN$", GRN);
      arg = replace_string(arg, "$YEL$", YEL);
      arg = replace_string(arg, "$BLU$", BLU);
      arg = replace_string(arg, "$MAG$", MAG);
      arg = replace_string(arg, "$CYN$", CYN);
      arg = replace_string(arg, "$WHT$", WHT);
      arg = replace_string(arg, "$HIR$", HIR);
      arg = replace_string(arg, "$HIG$", HIG);
      arg = replace_string(arg, "$HIY$", HIY);
      arg = replace_string(arg, "$HIB$", HIB);
      arg = replace_string(arg, "$HIM$", HIM);
      arg = replace_string(arg, "$HIC$", HIC);
      arg = replace_string(arg, "$HIW$", HIW);
      arg = replace_string(arg, "$NOR$", NOR);
      card->set("post_msg",arg+NOR+"\n");     
      write("ok!现在可用post ID可寄出贺卡。
用check card指令可以查看效果,如不满意,可擦除(dismodify card)。\n");
  }
 
  return 1;
} 


