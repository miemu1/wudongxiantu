// globals.h
#include "ansi.h"
#include "zjmud.h"
#include "tomud.h"
//#pragma save_binary
#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected static
#else
#define private protected
#define static nosave
#endif
// Important directories
#define BACKUP_DIR      "/backup/"
#define COMMAND_DIR     "/cmds/"
#define CONFIG_DIR      "/adm/etc/"
#define DATA_DIR	"/data/"
#define DUMP_DIR	"/dump/"
#define EVENT_DIR       "/adm/daemons/event/"
#define HELP_DIR	"/help/"
#define INC_DIR	 "/include/"
#define ITEM_DIR	DATA_DIR "item/"
#define LOG_DIR	 "/log/"
#define QUEST_DIR       "/adm/daemons/quest/"
#define	SHADOW_DIR	"/shadow/"
#define STORY_DIR       "/adm/daemons/story/"
#define TEMP_DIR	"/temp/"

// Daemons
#define AFK_D	 	"/adm/daemons/afkd"
#define ALIAS_D	 "/adm/daemons/aliasd"
#define WABAO_D	 "/adm/daemons/wabaod"

#define GIFT_D	   "/adm/daemons/giftd"
#define DAILY_D	    "/adm/daemons/daily"
#define BIWU_D		"/adm/daemons/biwud"
#define BAN_D	   "/adm/daemons/band"
#define JIHUO_D	   "/adm/daemons/jihuod"

#define WARS_D	   "/adm/daemons/warsd"
#define BACKUP_D	"/adm/daemons/backupd"
#define BANGHUI_D	"/adm/daemons/banghuid"

#define BOSSD_D	"/adm/daemons/bossdd"
#define BUILD_D	"/adm/daemons/buildd"
#define CHANNEL_D       "/adm/daemons/channeld"
#define CHAR_D	  "/adm/daemons/chard"
#define CHINESE_D       "/adm/daemons/chinesed"
#define CLOSE_D	 "/adm/daemons/closed"
#define COMBAT_D	"/adm/daemons/combatd"
#define COMMAND_D       "/adm/daemons/commandd"
#define CONFIG_D	"/adm/daemons/configd"
#define CPU_D	   "/adm/daemons/cpud"
#define DBASE_D	 "/adm/daemons/dbased"
#define EMOTE_D	 "/adm/daemons/emoted"
#define EVENT_D	 "/adm/daemons/eventd"
#define EXAMINE_D       "/adm/daemons/examined"
#define FAMILY_D	"/adm/daemons/familyd"
#define FINGER_D	"/adm/daemons/fingerd"
#define FTP_D	   "/adm/daemons/ftpd"
#define FUBEN_D	   "/adm/daemons/fubend"
#define VIP_D	   "/adm/daemons/vipd"
#define RANK_D	  "/adm/daemons/rankd"
#define INQUIRY_D       "/adm/daemons/inquiryd"
#define ITEM_D	  "/adm/daemons/itemd"
#define LEAGUE_D	"/adm/daemons/leagued"
#define LOGIN_D	 "/adm/daemons/logind"
#define MAIL_D		"/adm/daemons/maild"
#define MAP_D		"/adm/daemons/mapd"
#define MESSAGE_D	"/adm/daemons/network/messaged"
#define MERIDIAN_D	"/adm/daemons/meridiand"
#define MONEY_D	 "/adm/daemons/moneyd"
#define NAME_D	  "/adm/daemons/named"
#define NATURE_D	"/adm/daemons/natured"
#define NEWS_D	  "/adm/daemons/newsd"
#define NPC_D	   "/adm/daemons/npcd"
#define PIG_D	   "/adm/daemons/pigd"
#define PK_D	    "/adm/daemons/pkd"
#define PROFILE_D       "/adm/daemons/profiled"
#define QUEST_D	 	"/adm/daemons/questd"
#define SECURITY_D      "/adm/daemons/securityd"
#define STORY_D	 	"/adm/daemons/storyd"
#define TOP_D	 	"/adm/daemons/topd"
#define UPDATE_D	"/adm/daemons/updated"
#define VERSION_D       "/adm/daemons/versiond"
#define VIRTUAL_D       "/adm/daemons/virtuald"
#define FARM_D       "/adm/daemons/farmd"
#define WEAPON_D	"/adm/daemons/weapond"
#define WEEKLY_D	"/adm/daemons/weeklyd"
#define SALE_D	"/adm/daemons/saled"
#define PAY_D	"/adm/daemons/payd"
#define PAYDD	"/adm/daemons/paydd"

#define MASTER_D	"/adm/daemons/masterd"
#define HONGBAO_D	"/adm/daemons/hongbaod"


#define CLASS_D(x)      ("/kungfu/class/" + x)
#define CONDITION_D(x)  ("/kungfu/condition/" + x)
#define SKILL_D(x)      ("/kungfu/skill/" + x)
#define SPECIAL_D(x)    ("/kungfu/special/" + x)

// Clonable/Non-inheritable Standard Objects
#define CASH_OB	 "/clone/money/cash"
#define COIN_OB	 "/clone/money/coin"
#define CORPSE_OB       "/clone/misc/corpse"
#define GOLD_OB	 "/clone/money/gold"
#define LOGIN_OB	"/clone/user/login"
#define MASTER_OB       "/adm/single/master"
#define MAILBOX_OB      "/clone/misc/mailbox"
#define SILVER_OB       "/clone/money/silver"
#define SIMUL_EFUN_OB   "/adm/single/simul_efun"
#define TEMP_OB	 "/clone/misc/temp"
#define USER_OB	 "/clone/user/user"
#define VOID_OB	 "/clone/misc/void"
#define BAIBAO_OB	"/clone/misc/baibao"

// Inheritable Standard Objects
#define BANK	    "/inherit/room/bank"
#define BUILD_ROOM      "/inherit/room/buildroom"
#define BULLETIN_BOARD  "/inherit/misc/bboard"
#define CHALLENGER      "/inherit/char/challenger"
#define CHARACTER       "/inherit/char/char"
#define COMBINED_ITEM   "/inherit/item/combined"
#define EQUIP	   "/inherit/misc/equip"
#define FIGHTER	 "/inherit/char/fighter"
#define FORCE	   "/inherit/skill/force"
#define HOCKSHOP	"/inherit/room/hockshop"
#define ILLNESS	 "/inherit/condition/illness"
#define ITEM	    "/inherit/item/item"
#define KNOWER	  "/inherit/char/knower"
#define LIQUID	  "/inherit/food/liquid"
#define MONEY	   "/inherit/item/money"
#define NPC	     "/inherit/char/npc"
#define	PIG_ROOM	"/inherit/room/pigroom"
#define PILL	    "/inherit/medicine/pill"
#define POISON	  "/inherit/condition/poison"
#define POISON_INSECT   "/inherit/char/insect"
#define POWDER	  "/inherit/medicine/powder"
#define PRIVATE_ROOM    "/inherit/room/privateroom"
#define ROOM	    "/inherit/room/room"
#define SHAOLIN_SKILL   "/inherit/skill/shaolin"
#define SKILL	   "/inherit/skill/skill"
#define SNAKE	   "/inherit/char/snake"
#define COMBINED_ITEM_BANG   "/inherit/item/combined_bang"

#define F_GEMS			"/feature/gems.c"
#define S_ARMOR		"/inherit/gems/armor"
#define S_BOOTS		"/inherit/gems/boots"
#define S_HEAD		"/inherit/gems/head"
#define S_NECK		"/inherit/gems/neck"
#define S_SHIELD	"/inherit/gems/shield"
#define S_SURCOAT	"/inherit/gems/surcoat"
#define S_WAIST		"/inherit/gems/waist"
#define S_WRISTS	"/inherit/gems/wrists"
#define S_PANTS		"/inherit/gems/pants"
#define S_HAND		"/inherit/gems/hand.c"
#define S_WEAPON		"/inherit/gems/weapon.c"
#define S_ROBE			"/inherit/gems/robe.c"
#define S_RING			"/inherit/gems/ring.c"
#define S_FABAO		"/inherit/gems/fabao"
#define S_CHIBANG		"/inherit/gems/chibang"
#define S_SHOUHUAN		"/inherit/gems/shouhuan"
// User IDs
#define ROOT_UID	"Root"
#define BACKBONE_UID    "Backbone"

// Features
#define F_ACTION	"/feature/action.c"
#define F_ALIAS	 "/feature/alias.c"
#define F_APPRENTICE    "/feature/apprentice.c"
#define F_ATTACK	"/feature/attack.c"
#define F_ATTRIBUTE     "/feature/attribute.c"
#define F_AUTOLOAD      "/feature/autoload.c"
#define F_BANKER	"/feature/banker.c"
#define F_CLEAN_UP      "/feature/clean_up.c"
#define F_COAGENT       "/feature/coagent.c"
#define F_COMMAND       "/feature/command.c"
#define F_CONDITION     "/feature/condition.c"
#define F_CUTABLE       "/feature/cutable.c"
#define F_DAMAGE	"/feature/damage.c"
#define F_DBASE	 "/feature/dbase.c"
#define F_DEALER	"/feature/dealer.c"
#define F_EDIT	  "/feature/edit.c"
#define F_EQUIP	 "/feature/equip.c"
#define F_FINANCE       "/feature/finance.c"
#define F_FOOD	  "/feature/food.c"
#define F_GUARDER       "/feature/guarder.c"
#define F_ITEMMAKE      "/feature/itemmake.c"
#define F_LIQUID	"/feature/liquid.c"
#define F_MASTER	"/feature/master.c"
#define F_MESSAGE       "/feature/message.c"
#define F_MORE	  "/feature/more.c"
#define F_MOVE	  "/feature/move.c"
#define F_NAME	  "/feature/name.c"
#define F_NOCLONE       "/feature/noclone.c"
#define F_OBSAVE	"/feature/obsave.c"
#define F_PUNISHER      "/feature/punisher.c"
#define F_QUESTER       "/feature/quester.c"
#define F_SAVE	  "/feature/save.c"
#define F_SHADOW	"/feature/shadow.c"
#define	F_SILENTDEST	"/feature/silentdest.c"
#define F_SKILL	 "/feature/skill.c"
#define F_SSERVER       "/feature/sserver.c"
#define F_TEAM	  "/feature/team.c"
#define F_TRANSPORT     "/feature/transport.c"
#define F_TREEMAP       "/feature/treemap.c"
#define F_VENDOR	"/feature/dealer.c"
#define F_UNIQUE	"/feature/unique.c"
#define F_LEVEL	"/feature/level.c"
#define F_SUIT		"/feature/suit.c"	   //��װ
#define F_LEVELL	"/feature/levell.c"

//
#define SKILL_MODEL_UNARMED    "/clone/meskill/skill_model_unarmed.h"
#define SKILL_MODEL_WEAPON     "/clone/meskill/skill_model_weapon.h"
#define SKILL_MODEL_DEFAULT    "/clone/meskill/skill_model_default.h"

// music instructment
#define F_XIAO	  "/inherit/misc/_xiao.c"

// Others

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

// Install information
#define INSTALL_COMBAT_TEST     1

#undef PROFILE_COMMANDS
