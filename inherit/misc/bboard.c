// bbsboard.c
// updated by Lonely
/* 增强功能留言版：BBS_BOARD ，增加：回复功能、斑竹功能、整理功能
 * 防止 FLOOD 功能，参考于 jjgod 的留言版 */

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

#define BBS             "\n\nBbs - http://bbs.mudbuilder.com/"

// 最多容纳 100 个贴子
#define MAX_PLAN                1000

// 假如贴子超过了 MAX_PLAN，删掉前 25 个
#define DEL_TO          MAX_PLAN/4

// 是否保存所有原来的贴子，是则设为0，否则设为 1
#define SAVE_ALL_OLD_PLAN 0

// 如果需要显示整理情况（很长很长），请：
#define DEBUG           1

// 最大的标题长度
#define MAX_TITLE_LEN   29

// 发表文章需要的能力
#define NEED_EXP                10000
#define NEED_AGE                16

void setup()
{
        string loc;
        string my_long, my_id;

        if (stringp(loc = query("location")))
                move(loc);

        my_long = query("long");
        my_id = query("board_id");

        restore();

        set("no_get", 1);
        set("long", my_long);
        set("id", "board");
        set("location", loc);
}

void init()
{
        add_action("do_post", "post");
        add_action("do_re", "re");
        add_action("do_followup", "followup");
        add_action("do_read", "read");
        add_action("delete_post", "delete");
        add_action("delete_post", "discard");
        add_action("do_from", "from");
        add_action("do_banzhu", "banzhu");
        add_action("do_search", "search");
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("board_id")) ) return 0;
        return DATA_DIR + "board/" + id;
}

string short()
{
        mapping *notes;
        string banzhu;
        int i, unread, last_read_time;

        if (! query("banzhu"))
                banzhu = "[斑竹征求中]";
        else
                banzhu = "[斑竹:" + this_object()->query("banzhu") + "]";

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                return ::short() + " [ 没有任何贴子 ]";

        if (this_player())
        {
                last_read_time = (int)this_player()->query("board_last_read/" +
                                 (string)query("board_id"));
                for (unread = 0, i = sizeof(notes) - 1; i >= 0; i--, unread ++)
                        if( notes[i]["time"] <= last_read_time ) break;
        }
        if (unread)
                return sprintf(HIC "%s" NOR " [ " HIW "%d" NOR " 个贴子，" HIR "%d" NOR " 篇未读 ]" +
                               banzhu, ::short(), sizeof(notes), unread);
        else
                return sprintf("%s [ " HIW "%d" NOR " 个贴子 ]" + banzhu, ::short(), sizeof(notes));
}

string long()
{
        mapping *notes;
        int i, j, last_time_read;
        string msg, myid;

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                return query("long");

        msg = query("long") + (query("banzhu") ? ("这个版的的版主是 " WHT + query("banzhu") + NOR "。\n") : "") +
              HIW "编号──标题────────────────作者─回复───时间─────\n" NOR;

        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

        for (i = 0; i < sizeof(notes); i++)
        {
                msg += sprintf("%s[" WHT "%3d" NOR "]" NOR "  %-29s %12s " WHT "%+3d" NOR "   [%s]\n",
                        (notes[i]["time"] > last_time_read ? HIY: ""),
                        i + 1, notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]),
                        ctime(notes[i]["time"])[0..15] );
        }

        msg += HIW "─────────────────────────────────────\n" NOR;
        return msg;
}


int do_from(string arg)
{
        mapping *notes;
        int i,j,last_time_read;
        string msg, myid;

        notes = query("notes");
        msg = query("long");
        msg = msg + "留言版的使用方法请见 help board。\n";
        if (! pointerp(notes) || ! sizeof(notes)) return notify_fail(query("long"));

        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

        if (!arg)
                i = 0;
        else
                i = atoi(arg) - 1;

        if (i < 0) i = 0;

        j = 0;
        for (; i < sizeof(notes); i++)
        {
                msg += sprintf("%s[%3d]" NOR "  %-40s %12s (%s)\n",
                        (notes[i]["time"] > last_time_read ? HIY: ""),
                        i + 1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15]);
                j ++;
                if (j>1000) break;
        }

        this_player()->start_more(msg);
        return 1;
}

void done_post(object me, mapping note, int n, string text)
{
        int i, j;
        int t;
        int pl;
        string sign;
        string pure;
        mapping *notes;
        string *lines;
        string msg = "";

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "你的留言中短句太多了，请调整一下以便他人阅读。\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "你留言中有些行太长了，请分行以便他人阅读。\n");
                        return;
                }
        }

        if (! n) n = me->query("env/default_sign");
        if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
        {
                // auto select the first none null sign
                for (i = 1; i <= 4; i++)
                {
                        sign = me->query(sprintf("env/sign%d", i));
                        if (stringp(sign)) break;
                }
        }

        if (stringp(sign))
        {
                sign = replace_string(sign, "\\n", "\n");
                sign = trans_color(sign, 1);
                pure = filter_color(sign);
                if (strlen(pure) >= 1 &&
                    pure[strlen(pure) - 1] != '\n')
                        sign += "\n";

                pure = filter_color(text);
                pl = strlen(pure);
                if (pl >= 1 && pure[pl - 1] != '\n')
                        text += "\n\n" + sign;
                else
                if (pl >= 2 && pure[pl - 2] != '\n')
                        text += "\n" + sign;
                else
                        text += sign;
        } // else text += HIM "\n" + BBS + "\n" NOR;

        text = color_filter(text) + NOR;
        note["msg"] = text;
        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
                notes = ({ note });
        else
        {
                i = sizeof(notes) - 1;
                if (note["time"] <= notes[i]["time"])
                        note["time"] = notes[i]["time"] + 1;
                notes += ({ note });
        }

        set("notes", notes);
        tell_object(me, HIW "新贴子完成。\n" NOR);
        save();

        if (sizeof(query("notes")) > MAX_PLAN)
        {
                tell_object(me, HIR "贴子数目超量，正在整理……\n" NOR);
                for (i = 0; i < DEL_TO; i++)
                {
                        // 原文内容
                        msg += sprintf("[" WHT "%3d" NOR "] %-31s %14s [" WHT "%10s" NOR "]\n"
                                       "────────────────────────────────\n%s\n",
                        i + 1,
                        notes[i]["title"],
                        notes[i]["author"] + "-" + notes[i]["owner"],
                        ctime(notes[i]["time"])[0..9],
                        notes[i]["msg"],);
                        // 回复内容
                        if (sizeof(notes[i]["re"]))
                        {
                                for (j = 0; j < sizeof(notes[i]["re"]); j++)
                                {
                                        msg += sprintf("\n[ " WHT "回复：" NOR "%3d] %-26s %12s [" WHT "%10s" NOR "]\n"
                                                       "────────────────────────────────\n""%s\n",
                                        j + 1,
                                        notes[i]["re"][j]["title"],
                                        notes[i]["re"][j]["author"] + "-" +
                                        notes[i]["re"][j]["owner"],
                                        ctime(notes[i]["re"][j]["time"])[0..9],
                                        notes[i]["re"][j]["msg"],);
                                }
                        }
                }
#ifdef DEBUG
                me->start_more(msg);
#endif
                // 25 以前的贴子将保存到 /data/board/这里的board_id 文件中
                write_file(DATA_DIR + "board/" + query("board_id") + ".old", msg, SAVE_ALL_OLD_PLAN);
                // 删除目前 board 里的 25 以前的贴子
                notes = notes[DEL_TO..sizeof(notes)-1];
                set("notes", notes);
                save();
                tell_object(me, HIR "……整理完毕，删除 " HIW + (DEL_TO + 1) + HIR " 号以前的贴子。\n" NOR);
        }
        return;
}

void done_re(object me, mapping report, int project, int n, string text)
{
        int i;
        int t;
        int pl;
        string sign;
        string pure;
        mapping *notes, *reports;
        string *lines;
        mapping note;

        if (! stringp(text))
                return;

        if (strlen(text) > 64 * 1024)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        lines = explode(text, "\n");
        i = sizeof(lines);
        if (i > 2000)
        {
                tell_object(me, "你的留言太长了，请略去一些不必要的。\n");
                return;
        }

        if (i > 20 && strlen(text) / i < 10)
        {
                tell_object(me, "你的留言中短句太多了，请调整一下以便他人阅读。\n");
                return;
        }

        while (i--)
        {
                // scan all lines
                if (strlen(lines[i]) > 300)
                {
                        tell_object(me, "你留言中有些行太长了，请分行以便他人阅读。\n");
                        return;
                }
        }

        if (! n) n = me->query("env/default_sign");
        if (! stringp(sign = me->query(sprintf("env/sign%d", n))))
        {
                // auto select the first none null sign
                for (i = 1; i <= 4; i++)
                {
                        sign = me->query(sprintf("env/sign%d", i));
                        if (stringp(sign)) break;
                }
        }

        if (stringp(sign))
        {
                sign = replace_string(sign, "\\n", "\n");
                sign = trans_color(sign, 1);
                pure = filter_color(sign);
                if (strlen(pure) >= 1 &&
                    pure[strlen(pure) - 1] != '\n')
                        sign += "\n";

                pure = filter_color(text);
                pl = strlen(pure);
                if (pl >= 1 && pure[pl - 1] != '\n')
                        text += "\n\n" + sign;
                else
                if (pl >= 2 && pure[pl - 2] != '\n')
                        text += "\n" + sign;
                else
                        text += sign;
        } // else text += HIM "\n" + BBS + "\n" NOR;

        text = color_filter(text) + NOR;
        report["msg"] = text;

        notes = query("notes");
        reports = notes[project]["re"];

        if (! arrayp(reports))
                reports = ({ report });
        else
                reports += ({ report });

        notes[project]["re"] = reports;
        notes[project]["time"] = time();

        set("notes", notes);
        tell_object(me, HIW "回复完毕。\n" NOR);

        save();
        return;
}

int do_post(string arg, int n)
{
        mapping note, fam;
        int noname_board;
        string poster_lvl, family;
        object me = this_player();

        poster_lvl = query("poster_level");

        if (! stringp(poster_lvl))
                poster_lvl = "(player)";

        // write("Board Restricted to " + poster_lvl + " and above.\n");

        if ((int)SECURITY_D->check_wiz_level(me, poster_lvl) < 0)
                return notify_fail("本板不接受你的投稿。\n");

        family = query("poster_family");
        fam = me->query("family");
        noname_board = query("noname_board");

        // write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && (int)SECURITY_D->check_wiz_level(me, "(immortal)") < 0
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("非本派弟子不得向本板乱涂乱写。\n");

        if (query("avoid_flood")
                && me->query("combat_exp") < NEED_EXP
                && me->query("age") < NEED_AGE)
                return notify_fail("你暂时还没有权力在这里发表文章，需要 " WHT +
                                   NEED_EXP + NOR " 点修为值或者 " WHT + NEED_AGE + NOR " 岁的年龄。\n");

        if (! arg) return notify_fail("新贴子请指定一个标题。\n");

        if (sscanf(arg, "%s with %d", arg, n) != 2)
                n = 0;

        if (replace_string(arg, " ", "") == "")
                arg = "无标题";
        /*
        else
                arg = color_filter(arg) + NOR;
        */
        if (strlen(arg) > MAX_TITLE_LEN)
                return notify_fail("这个标题太长了，请换一个简洁一点的。\n");

        note = allocate_mapping(5);
        note["title"] = arg;
        if (noname_board)
        {
                note["owner"] = "NULL";
                note["author"] = "匿名";
        }
        else
        {
                note["owner"] = me->query("id");
                note["author"] = me->name(1);
        }
        note["time"] = time();
        me->edit((: done_post, me, note, n :));
        return 1;
}

int do_re(string arg, int n)
{
        int num, noname_board;
        string title;
        mapping note, *notes, fam;
        string poster_lvl, family;
        object me = this_player();

        poster_lvl = query("poster_level");

        if (! stringp(poster_lvl))
                poster_lvl = "(player)";

        // write("Board Restricted to " + poster_lvl + " and above.\n");

        if ((int)SECURITY_D->check_wiz_level(me, poster_lvl) < 0)

                return notify_fail("本板不接受你的投稿。\n");

        family = query("poster_family");
        fam = me->query("family");
        noname_board = query("noname_board");

        // write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && (int)SECURITY_D->check_wiz_level(me, "(immortal)") < 0
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("非本派弟子不得向本板乱涂乱写。\n");

        if (query("avoid_flood")
                && me->query("combat_exp") < NEED_EXP
                && me->query("age") < NEED_AGE)
                return notify_fail("你暂时还没有权力在这里发表文章，需要 " WHT +
                                   NEED_EXP + NOR " 点修为值或者 " WHT + NEED_AGE + NOR " 岁的年龄。\n");

        if (! arg) return notify_fail("指令格式：re <贴子编号>.<回复标题> with <签名档>\n");

        if (sscanf(arg, "%d.%s", num, title) < 1)
                return notify_fail("指令格式：re <贴子编号>.<回复标题> with <签名档>\n");

        if (sscanf(arg, "%d.%s with %d", num, title, n) != 3
                && sscanf(arg, "%d with %d", num, n) != 2)
                n = 0;

        notes = query("notes");
        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
                return notify_fail("没有这个贴子。\n");

        if (strlen(title)>MAX_TITLE_LEN)
                return notify_fail("这个标题太长了，请换一个简洁一点的。\n");

        if (! title) title = "Re: " + notes[num - 1]["title"];
        /*
        else
                title = color_filter(title) + NOR;
        */

        note = allocate_mapping(5);
        note["title"] = title;
        if (noname_board)
        {
                note["owner"] = "NULL";
                note["author"] = "匿名";
        }
        else
        {
                note["owner"] = me->query("id");
                note["author"] = me->name(1);
        }
        note["time"] = time();
        me->edit((: done_re, me, note, num - 1, n :));
        return 1;
}

int do_followup(string arg)
{
        int n, num, noname_board;
        string title, file, msg = "";
        mapping note, *notes, fam;
        string poster_lvl, family;
        object me = this_player();

        poster_lvl = query("poster_level");

        if (! stringp(poster_lvl))
                poster_lvl = "(player)";

        // write("Board Restricted to " + poster_lvl + " and above.\n");

        if ((int)SECURITY_D->check_wiz_level(me, poster_lvl) < 0)

                return notify_fail("本板不接受你的投稿。\n");

        family = query("poster_family");
        fam = me->query("family");
        noname_board = query("noname_board");

        // write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && (int)SECURITY_D->check_wiz_level(me, "(immortal)") < 0
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("非本派弟子不得向本板乱涂乱写。\n");

        if (query("avoid_flood")
                && me->query("combat_exp") < NEED_EXP
                && me->query("age") < NEED_AGE)
                return notify_fail("你暂时还没有权力在这里发表文章，需要 " WHT +
                                   NEED_EXP + NOR " 点修为值或者 " WHT + NEED_AGE + NOR " 岁的年龄。\n");

	if( !arg )
		return notify_fail("请输入欲回覆的文章编号或 last 回覆最后一篇文章。\n");

        notes = query("notes");

	if( arg == "last" ) num = sizeof(notes);
	else
        if (sscanf(arg, "%d %s", num, title) < 1)
                return notify_fail("请输入欲回覆的文章编号。\n");

        if (sscanf(arg, "%d %s with %d", num, title, n) != 3
                && sscanf(arg, "%d with %d", num, n) != 2)
                n = 0;

        if (! arrayp(notes) || num < 1 || num > sizeof(notes))
                return notify_fail("没有这张留言。\n");

        if (title && strlen(title) > MAX_TITLE_LEN)
                return notify_fail("这个标题太长了，请换一个简洁一点的。\n");

	num--;
	file = notes[num]["msg"];

	foreach( string word in explode( file, "\n" ) )
	{
		if( word == "" || word[0..7]=="[1;30m>" ) continue;
		else if( word[0..5] == "[33m>" ) msg += "[1;30m> "+word[5..]+"\n";
		else if( word[0..5] == "[36m>" ) msg += "[33m> "+word[5..]+"\n";
		else msg += "[36m> "+word+"\n";
	}

	if( msg[0..5] == "[36m>" )
		msg = "[36m> ◎" + notes[num]["author"] + " 在 " + ctime(notes[num]["time"]) + " 留下这篇留言：\n" + msg;

	msg += "\n◎" + me->query_idname() + " 在 " + ctime(time()) + " 留下这篇留言：\n";

	note = allocate_mapping(5);
	if (! title)
		title = (notes[num]["title"][0..5] != "回覆：" ? "回覆：" : "") + notes[num]["title"];

        note["title"] = title;
        if (noname_board)
        {
                note["owner"] = "NULL";
                note["author"] = "匿名";
        }
        else
        {
                note["owner"] = me->query("id");
                note["author"] = me->name(1);
        }
        note["time"] = time();
        me->edit((: done_post, me, note, n :), msg);
        return 1;
}

int do_read(string arg)
{
        int num, rep, last_read_time, i, last, arc, private_board;
        mapping *notes, fam;
        string myid, msg, file;
        string family;
        object me = this_player();

        last_read_time = me->query("board_last_read/" + query("board_id"));
        myid    = query("board_id");
        notes   = query("notes");
        arc = query("wizard_only");
        private_board = query("private_board");

        if (arc && ! wizardp(me))
                return notify_fail("巫师内部交流不得窥视。\n");

        family = query("poster_family");
        fam = me->query("family");

        //write("Board Restricted to " + family + " players only.\n");

        if (stringp(family)
                && ! wizardp(me)
                && (! mapp(fam) || fam["family_name"] != family))
                return notify_fail("非本派弟子不得窥视本派内部交流。\n");

        if (! pointerp(notes) || ! sizeof(notes))
                return notify_fail("板子上目前没有任何贴子。\n");

        if (! arg) return notify_fail("指令格式：read <贴子编号>[.<回复编号>]|new|next|old\n");

        // 显示以前备份的旧贴子
        if (arg == "old")
        {
                file = DATA_DIR + "board/" + query("board_id") + ".old";
                if (file_size(file) <= 0)
                        return notify_fail("对不起，目前本版没有保存的旧贴。\n");
                else
                {
                        if (private_board && ! wizardp(me))
                                return notify_fail("对不起，由于旧贴涉及到一些个人隐私，故不开放阅读。\n");

                        msg = read_file(file);
                        me->start_more(msg);
                        return 1;
                }
        }
        // 显示未读的贴子
        if (arg == "new" || arg == "next")
        {
                if (! intp(last_read_time) || undefinedp(last_read_time))
                        num = 1;
                else
                        for (num = 1; num <= sizeof(notes); num++)
                                if (notes[num-1]["time"] > last_read_time)
                                {
                                        if (private_board)
                                        {
                                                if (wizardp(me)) break;
                                                else
                                                if (! strcmp(me->query("id"), notes[num - 1]["owner"]))
                                                        break;
                                        } else
                                                break;
                                }

        } else
        if (sscanf(arg, "%d.%d", num, rep) == 2)
        {
                if (num < 1 || num > sizeof(notes))
                        return notify_fail("没有这个贴子。\n");
                else num--;

                if (! wizardp(me) && private_board && strcmp(me->query("id"), notes[num]["owner"]))
                        return notify_fail("这个帖子不是你留的，所以你不能阅读。\n");

                if (rep < 1 || rep > sizeof(notes[num]["re"]))
                        return notify_fail("没有这个回复。\n");
                else rep --;

                me->start_more(sprintf("[ " HIW "编号：" NOR "%3d | " HIW "回复编号：" NOR "%3d] [ " HIW "原题：" NOR "%-27s ] \n"
                               "[ " HIW "回复标题：" NOR "%-51s ]\n────────────────────────────────\n"
                               "%s\n────────────────────────────────\n[ " HIW "时间：" NOR "%s ] [ "
                               HIW "作者：" NOR " %19s]\n",
                               num + 1, rep + 1,
                               notes[num]["title"],
                               notes[num]["re"][rep]["title"],
                               notes[num]["re"][rep]["msg"] + HIM "\n" + BBS + "\n" NOR,
                               ctime(notes[num]["re"][rep]["time"]),
                               notes[num]["re"][rep]["author"] + "(" +
                               notes[num]["re"][rep]["owner"] + ")"));

                if (notes[num]["time"] > last_read_time)
                        me->set("board_last_read/" + query("board_id"),
                               notes[num]["time"]);

                return 1;
        } else
        if (! sscanf(arg, "%d", num))
                return notify_fail("你要读第几个贴子的回复？\n");

        if (num < 1 || num > sizeof(notes))
                return notify_fail("没有这个贴子。\n");
        num--;

        if (! wizardp(me) && private_board && strcmp(me->query("id"), notes[num]["owner"]))
                return notify_fail("这个帖子不是你留的，所以你不能阅读。\n");

        msg = sprintf("[ " HIW "编号：" NOR "%3d ] [ " HIW "作者：" NOR "%20s ] [ " HIW "时间：" NOR "%-9s ]\n[ "
                      HIW "标题：" NOR "%-55s ]\n─────────────" WHT "[Content-]" NOR "──────────────\n%s\n"
                      "──────────────" WHT "[-End]" NOR "───────────────\n",
                      num + 1,
                      notes[num]["author"] + "(" + notes[num]["owner"] + ")",
                      ctime(notes[num]["time"])[0..9],
                      notes[num]["title"],
                      notes[num]["msg"] + HIM "\n" + BBS + "\n" NOR);
        // 显示回复的数目
        if (sizeof(notes[num]["re"]) && me->query("env/show_reply") != "all")
                msg += sprintf(HIW "回复：" NOR "%d 份。\n", sizeof(notes[num]["re"]));

        // 显示最后的一个回复
        if (me->query("env/show_reply") == "last")
        {
                last = sizeof(notes[num]["re"]) - 1;
                msg += sprintf(
                               "\n[ " HIW "回复编号：" NOR "%3d] [ " HIW "回复标题：" NOR "%-34s ] \n"
                               "────────────────────────────────\n"
                               "%s\n────────────────────────────────\n[ " HIW "时间：" NOR "%s ] [ "
                               HIW "作者：" NOR " %19s]\n",
                               last + 1,
                               notes[num]["re"][last]["title"],
                               notes[num]["re"][last]["msg"] + HIM "\n" + BBS + "\n" NOR,
                               ctime(notes[num]["re"][last]["time"]),
                               notes[num]["re"][last]["author"] + "(" +
                               notes[num]["re"][last]["owner"] + ")");
        }
        // 显示所有的回复
        if (me->query("env/show_reply") == "all")
        {
                for (i = 0; i < sizeof(notes[num]["re"]); i++)
                {
                        msg += sprintf(
                                       "\n[ " HIW "回复编号：" NOR "%3d] [ " HIW "回复标题：" NOR "%-34s ] \n"
                                       "────────────────────────────────\n"
                                       "%s\n────────────────────────────────\n[ " HIW "时间：" NOR "%s ] [ "
                                       HIW "作者：" NOR " %19s]\n",
                                       i+1,
                                       notes[num]["re"][i]["title"],
                                       notes[num]["re"][i]["msg"] + HIM "\n" + BBS + "\n" NOR,
                                       ctime(notes[num]["re"][i]["time"]),
                                       notes[num]["re"][i]["author"] + "(" +
                                       notes[num]["re"][i]["owner"] + ")");
                }
        }
        me->start_more(msg);

        if (notes[num]["time"] > last_read_time)
                me->set("board_last_read/" + query("board_id"),
                        notes[num]["time"]);

        return 1;
}


int do_banzhu(string arg)
{
        if (! arg) return notify_fail("指令格式： banzhu <版主id>\n");

        if (! stringp(arg) || strlen(arg) < 3)
                return notify_fail("没有这个人。\n");

        if (query("banzhu") == arg)
                return notify_fail("目前的版主就是 " + arg + "，不需要设置。\n");

        if (SECURITY_D->get_status(this_player(1)) != "(admin)" &&
            query("owner_id") != this_player()->query("id"))
                return notify_fail("你不是天神，不可以设置版主。\n");

        set("banzhu", arg);
        write("设置 " HIW + arg + NOR " 为" + name() + "版主成功。\n");
        save();
        return 1;
}

int delete_post(string arg)
{
        mapping *notes;
        int num, re_num;

        if (! arg ||sscanf(arg, "%d.%d", num, re_num) < 1)
                return notify_fail("指令格式：delete <贴子编号>[.<回复编号>]\n");

        notes = query("notes");
        if (! arrayp(notes)|| num < 1 || num > sizeof(notes))
                return notify_fail("没有这张贴子。\n");

        else
        if (re_num)
        {
                if (re_num < 1 || ! arrayp(notes[num - 1]["re"])
                        || re_num > sizeof(notes[num - 1]["re"]))
                        return notify_fail("没有这张回复。\n");
                else
                {
                        num--;
                        re_num--;

                        if (notes[num]["re"][re_num]["owner"] != (string)this_player(1)->query("id")
                                && query("banzhu") != this_player(1)->query("id")
                                && (string)SECURITY_D->get_status(this_player(1)) != "(admin)")
                                return notify_fail("这个回复不是你写的，你又不是版主。\n");

                        else
                        {
                                notes[num]["re"] = notes[num]["re"][0..re_num-1] + notes[num]["re"][re_num+1..sizeof(notes[num]["re"])-1];
                                set("notes", notes);
                                write("删除第 " + (num+1) + " 号贴子的第 "+ (re_num + 1) + " 号回复....Ok。\n");
                                save();
                                return 1;
                        }
                }
        } else
        {
                num--;
                if (notes[num]["owner"] != (string)this_player(1)->query("id")
                        && query("banzhu") != this_player(1)->query("id")
                        && (string)SECURITY_D->get_status(this_player(1)) != "(admin)")
                        return notify_fail("这个贴子不是你写的，你又不是版主。\n");

                notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
                set("notes", notes);
                write("删除第 " + (num + 1) + " 号贴子....Ok。\n");
                save();
                return 1;
        }
}


int do_search(string arg)
{
        mapping *notes;
        int i, last_time_read, j = 0;
        string msg, topic, note;
        object me = this_player();

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "目前没有任何帖子。\n");
                return 1;
        }

        if (! arg)
        {
                tell_object(me, "你想搜索那一条帖子？\n");
                return 1;
        }

        if (sscanf(arg, "%s %s", topic, arg) != 2)
        {
                tell_object(me, "你只能搜索标题(title)、作者(author)、内容(document)。\n");
                return 1;
        } else
        {
                if (topic == "title") note = "标题";
                else
                if (topic == "author") note = "作者";
                else
                if (topic == "document") note = "内容";
                else
                {
                        tell_object(me, "你只能搜索标题(title)、作者(author)、内容(document)。\n");
                        return 1;
                }
        }

        last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
        i = sizeof(notes);

        msg = sprintf("根据 " HIY "%s" NOR " 搜索 " HIY "%s" NOR " 得到如下符合条件帖子：\n"
                      HIW "编号──标题────────────────作者─回复───时间─────\n" NOR,
                      arg, note);

        while (i--)
        {
                if (topic == "document")
                {
                        if (strsrch(notes[i]["msg"], arg) == -1)
                                continue;
                } else
                {
                        if (strsrch(notes[i][topic], arg) == -1)
                                continue;
                }

                msg += sprintf("%s[" WHT "%3d" NOR "]" NOR "  %-29s %12s " WHT "%+3d" NOR "   [%s]\n",
                               (notes[i]["time"] > last_time_read ? HIY: ""),
                               i + 1, notes[i]["title"], notes[i]["author"], sizeof(notes[i]["re"]),
                               ctime(notes[i]["time"])[0..15] );

                j++;
                if (j > 19)
                {
                        msg += "由于搜索到的结果太多，因此只显示二十条留言，请使用更明确的关键字|词。\n";
                        break;
                }
        }

        if (j == 0)
        {
                tell_object(me, "根据 " HIY + arg + NOR " 搜索 " HIY + note + NOR " 没有找到符合条件的帖子。\n");
                return 1;
        }

        msg += HIW "─────────────────────────────────────\n" NOR;
        me->start_more(msg);
        return 1;
}

