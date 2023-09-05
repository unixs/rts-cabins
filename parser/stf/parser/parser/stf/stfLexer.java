// Generated from parser/stf/stf.g4 by ANTLR 4.13.0
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class stfLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		MAGIC_HEADING=1, LEFT_PAREN=2, RIGHT_PAREN=3, STRING=4, COMMA=5, PLUS=6, 
		LETTER=7, DIGIT=8, DASH=9, DOT=10, WS=11, NEWLINE=12;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"MAGIC_HEADING", "LEFT_PAREN", "RIGHT_PAREN", "STRING", "COMMA", "PLUS", 
			"LETTER", "DIGIT", "DASH", "DOT", "WS", "NEWLINE"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'SIMISA@@@@@@@@@@JINX0t1t______'", "'('", "')'", null, "','", 
			"'+'", null, null, "'-'", "'.'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "MAGIC_HEADING", "LEFT_PAREN", "RIGHT_PAREN", "STRING", "COMMA", 
			"PLUS", "LETTER", "DIGIT", "DASH", "DOT", "WS", "NEWLINE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public stfLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "stf.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\fW\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002"+
		"\u0001\u0003\u0001\u0003\u0005\u0003?\b\u0003\n\u0003\f\u0003B\t\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001"+
		"\t\u0001\t\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001@\u0000\f\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005"+
		"\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0001"+
		"\u0000\u0004\u0003\u0000AZ__az\u0001\u000009\u0002\u0000\t\t  \u0002\u0000"+
		"\n\n\r\rW\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000"+
		"\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000"+
		"\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000"+
		"\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000"+
		"\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000"+
		"\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000"+
		"\u0001\u0019\u0001\u0000\u0000\u0000\u00038\u0001\u0000\u0000\u0000\u0005"+
		":\u0001\u0000\u0000\u0000\u0007<\u0001\u0000\u0000\u0000\tE\u0001\u0000"+
		"\u0000\u0000\u000bG\u0001\u0000\u0000\u0000\rI\u0001\u0000\u0000\u0000"+
		"\u000fK\u0001\u0000\u0000\u0000\u0011M\u0001\u0000\u0000\u0000\u0013O"+
		"\u0001\u0000\u0000\u0000\u0015Q\u0001\u0000\u0000\u0000\u0017S\u0001\u0000"+
		"\u0000\u0000\u0019\u001a\u0005S\u0000\u0000\u001a\u001b\u0005I\u0000\u0000"+
		"\u001b\u001c\u0005M\u0000\u0000\u001c\u001d\u0005I\u0000\u0000\u001d\u001e"+
		"\u0005S\u0000\u0000\u001e\u001f\u0005A\u0000\u0000\u001f \u0005@\u0000"+
		"\u0000 !\u0005@\u0000\u0000!\"\u0005@\u0000\u0000\"#\u0005@\u0000\u0000"+
		"#$\u0005@\u0000\u0000$%\u0005@\u0000\u0000%&\u0005@\u0000\u0000&\'\u0005"+
		"@\u0000\u0000\'(\u0005@\u0000\u0000()\u0005@\u0000\u0000)*\u0005J\u0000"+
		"\u0000*+\u0005I\u0000\u0000+,\u0005N\u0000\u0000,-\u0005X\u0000\u0000"+
		"-.\u00050\u0000\u0000./\u0005t\u0000\u0000/0\u00051\u0000\u000001\u0005"+
		"t\u0000\u000012\u0005_\u0000\u000023\u0005_\u0000\u000034\u0005_\u0000"+
		"\u000045\u0005_\u0000\u000056\u0005_\u0000\u000067\u0005_\u0000\u0000"+
		"7\u0002\u0001\u0000\u0000\u000089\u0005(\u0000\u00009\u0004\u0001\u0000"+
		"\u0000\u0000:;\u0005)\u0000\u0000;\u0006\u0001\u0000\u0000\u0000<@\u0005"+
		"\"\u0000\u0000=?\t\u0000\u0000\u0000>=\u0001\u0000\u0000\u0000?B\u0001"+
		"\u0000\u0000\u0000@A\u0001\u0000\u0000\u0000@>\u0001\u0000\u0000\u0000"+
		"AC\u0001\u0000\u0000\u0000B@\u0001\u0000\u0000\u0000CD\u0005\"\u0000\u0000"+
		"D\b\u0001\u0000\u0000\u0000EF\u0005,\u0000\u0000F\n\u0001\u0000\u0000"+
		"\u0000GH\u0005+\u0000\u0000H\f\u0001\u0000\u0000\u0000IJ\u0007\u0000\u0000"+
		"\u0000J\u000e\u0001\u0000\u0000\u0000KL\u0007\u0001\u0000\u0000L\u0010"+
		"\u0001\u0000\u0000\u0000MN\u0005-\u0000\u0000N\u0012\u0001\u0000\u0000"+
		"\u0000OP\u0005.\u0000\u0000P\u0014\u0001\u0000\u0000\u0000QR\u0007\u0002"+
		"\u0000\u0000R\u0016\u0001\u0000\u0000\u0000ST\u0007\u0003\u0000\u0000"+
		"TU\u0001\u0000\u0000\u0000UV\u0006\u000b\u0000\u0000V\u0018\u0001\u0000"+
		"\u0000\u0000\u0002\u0000@\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}