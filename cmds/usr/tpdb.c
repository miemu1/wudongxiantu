// top.c leeyao修改去bug版本(原来版本如果有断线玩家就出问题)
#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{

        object *list,*ob;
        int i;
        string msg;

        ob = filter_array(children(USER_OB),(: userp($1)  :));
        list = sort_array(ob, (: top_list :));
        msg ="\n\t　　┌ "+HIW+MUD_NAME+"护卫家国排行榜"NOR" ┐\n";
        msg += "┌───┬──────────┬────┐\n";
        msg += "│  名次 │    玩        家  \t\t\t\t\t\t\t\t│ 次 数 		│\n";
        msg += "├───┴──────────┴────┤\n";
        msg += "├注：截止活动结束。										┤\n";
        msg += "├第一名玩家奖励100天机点。								┤\n";
        msg += "├第二至第五名玩家奖励50天机点。			            	┤\n";
        msg += "├第五至第十名玩家奖励20天机点。							┤\n";
        msg += "├───┴──────────┴────┤\n";

        for (i = 0 ;i < 15 ; i++)
		{
			if( i >= sizeof(list))
                msg += sprintf("│  %-5s 暂时空缺。　　　　　　　　　　　　　　　│\n"NOR,chinese_number(i+1));
            else
			{
				if(list[i] == me)
					msg += HIC;
					msg += sprintf("│  %-5s%-22s\n"NOR,chinese_number(i+1),"\t		\t"+list[i]->query("name")+"\t\t\t\t\t\t				[ "+list[i]->query("guoqing/s1")+"次 ]");
            }
        }
        msg += "└─巫师、断线、睡眠、昏迷均不进入排名榜┘\n";
        msg += "  " + NATURE_D->game_time() + "记。\n";
		msg = replace_string(msg,"\n",ZJBR)+"\n";
		write(ZJOBLONG+msg+"\n");
       // write(msg);
        return 1;

}
int top_list(object ob1, object ob2)
{
	int score1,score2;

	score1 = get_score(ob1);
	score2 = get_score(ob2);

    return score2 - score1;
}

int get_score(object ob)
{
        int score;
        score = ob->query("guoqing/s1");
        return score;
}

int help(object me)
{
write(@HELP
指令格式 : top

这个指令可以让你知道在线十大高手是哪些，别去惹他们。

HELP
    );
    return 1;
}

