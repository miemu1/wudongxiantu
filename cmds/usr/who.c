// who.c
#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
#include <tomud.h>
#define ENGLISH_MUD_NAME INTERMUD_MUD_NAME
inherit F_CLEAN_UP;

void create();
nosave int busy=0;

void create() { seteuid(getuid()); }

void more_str(string tab, string str, int line, int page)
{
	int i, j, now, all;
	string show,*text,*topics,topic;

	show = tab;
	text = explode(str,"\n");
	all = sizeof(text)/line;
	if(sizeof(text)%line) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*line;
	i = page*line;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;
	topics = explode(str,"/");
	topic = topics[sizeof(topics)-1];
	show += sprintf("◎ %s("+MUD_NAME+")在线玩家(%d/%d页)：\n",CHINESE_MUD_NAME,page,all);
	show += ZJOBACTS2+ZJMENUF(2,2,7,30);
	show += "上一页:who "+(page-1)+ZJSEP"下一页:who "+(page+1)+ZJSEP;
	show += implode(text[j..i], ZJSEP);
	write(show+"\n");
}

mixed main(object me, string arg, int remote)
{
	string str,descc,mz,dengji,mp8;
	string menpai,mp7,mp6,level,levelll;//假人门派。

	object *ob;
	int page,i;
	string name, *option;
	object *list;
	int j, ppl_cnt,wiz_cnt;
	int opt_long, opt_id, opt_wiz;
	int SendInterMud=0;
	string HostName,strMsg;
	int type=0;
  
	str="";
	i=0;

	wiz_cnt = 0;
	ppl_cnt = 0;
	if(remote && sizeof(arg)<2) arg="";

	if( !arg )
	{
		page = 1;
	}
	else if(sscanf(arg,"%d",page)!=1)
	{
		page = 1;
	}
	if (wizardp(me))
		type = 1;
	list = sort_array(children(USER_OB), "sort_user2", this_object());
	j = sizeof(list);
	while( j-- )
	{
		if( !environment(list[j]) ) continue;
		if(me && !me->visible(list[j]) ) continue;
		if(!me && (int)list[j]->query("env/invisibility")>0 ) continue;
		
		if(!list[j]->query("family"))
		{

			menpai = "武林隐士"NOR;

		}
		else
		{
			menpai=list[j]->query("family/family_name");
		}
			mp7 = YEL"【 门 派 】 "NOR;
			mp6 = YEL"【 账 号 】 "NOR;

			mp8 = CYN"【 元 神 】 ";		
	level = HIR"(v";
	levelll= list[j]->query("vip/dj");
				descc = HIW"【 昵 称 】 "NOR;
				mz = list[j]->query("name");
				dengji = list[j]->query("yuanshen/level");
//		str += sprintf("%s"ZJBR+WHT"%s"NOR""ZJBR+WHT"%s"NOR"("HIG"%s"NOR"):look %s\n",list[j]->query("family/family_name"),list[j]->query("family/family_name"),list[j]->query("name"), type ? list[j]->query("id") : "***",list[j]->query("id"));
//		str += sprintf("%s"ZJBR+"%s""%d级"ZJBR+"""%s"    	HIG		"%s)"NOR":look %s\n",mp7+WHT+menpai+NOR,mp8+WHT,dengji
///		,descc,mz+level+levelll,list[j]->query("id"));	
if(wizardp(me)&&me->query("env/invisible")==1)
{
		str += sprintf("%s"ZJBR+"%s""%d级"ZJBR+"""%s"    	HIG		"%s"NOR":snoop %s\n",mp7+WHT+menpai+NOR,mp8+WHT,dengji
		,descc,mz,list[j]->query("id"));		
}else
{
		str += sprintf("%s"ZJBR+"%s""%d级"ZJBR+"""%s"    	HIG		"%s"NOR":look %s\n",mp7+WHT+menpai+NOR,mp8+WHT,dengji
		,descc,mz,list[j]->query("id"));	
}
		ppl_cnt ++;
		wiz_cnt ++;
	}

	more_str(ZJOBLONG, str, 10, page);
	return 1;		   
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;

	if( wizardp(ob1) && wizardp(ob2) )
	return (int)SECURITY_D->get_wiz_level(ob2) 
		- (int)SECURITY_D->get_wiz_level(ob1);

	if( ob1->query("id") && !ob2->query("id") )
	return -1;
	if( ob2->query("id") && !ob1->query("id") )
	return 1;
	if( !ob1->query("id") && !ob2->query("id") )
	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
	return strcmp(ob2->query("id"), ob1->query("id"));
}

int sort_user2(object ob1, object ob2)
{
	 return (int)ob1->query("combat_exp") - (int)ob2->query("combat_exp");
}

int help(object me)
{
write(@HELP
指令格式 : who [@<MudName>] [-l|-i|-w]

这个指令可以列出所有在线上或连线中的 Mud 的玩家及其等级。
@<MudName> [-l|-i|-w] 例：who @The.Master.Of.Hero -w

-l 选项列出较长的讯息。
-i 只列出玩家的英文代号。
-w 只列出线上所有的巫师。
 
相关指令： finger
HELP
	);
	return 1;
}

