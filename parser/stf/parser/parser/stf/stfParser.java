// Generated from parser/stf/stf.g4 by ANTLR 4.13.0
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class stfParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		MAGIC_HEADING=1, LEFT_PAREN=2, RIGHT_PAREN=3, STRING=4, COMMA=5, PLUS=6, 
		LETTER=7, DIGIT=8, DASH=9, DOT=10, WS=11, NEWLINE=12;
	public static final int
		RULE_stf = 0, RULE_heading = 1, RULE_node = 2, RULE_space = 3, RULE_nodeName = 4, 
		RULE_nodeList = 5, RULE_nodeListDelim = 6, RULE_nodeListItem = 7, RULE_term = 8, 
		RULE_string = 9, RULE_ident = 10, RULE_number = 11;
	private static String[] makeRuleNames() {
		return new String[] {
			"stf", "heading", "node", "space", "nodeName", "nodeList", "nodeListDelim", 
			"nodeListItem", "term", "string", "ident", "number"
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

	@Override
	public String getGrammarFileName() { return "stf.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public stfParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StfContext extends ParserRuleContext {
		public HeadingContext heading() {
			return getRuleContext(HeadingContext.class,0);
		}
		public List<NodeContext> node() {
			return getRuleContexts(NodeContext.class);
		}
		public NodeContext node(int i) {
			return getRuleContext(NodeContext.class,i);
		}
		public TerminalNode EOF() { return getToken(stfParser.EOF, 0); }
		public SpaceContext space() {
			return getRuleContext(SpaceContext.class,0);
		}
		public StfContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stf; }
	}

	public final StfContext stf() throws RecognitionException {
		StfContext _localctx = new StfContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_stf);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			heading();
			setState(25);
			node();
			setState(27);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(26);
				space();
				}
			}

			setState(32);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LETTER) {
				{
				{
				setState(29);
				node();
				}
				}
				setState(34);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(35);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class HeadingContext extends ParserRuleContext {
		public TerminalNode MAGIC_HEADING() { return getToken(stfParser.MAGIC_HEADING, 0); }
		public HeadingContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_heading; }
	}

	public final HeadingContext heading() throws RecognitionException {
		HeadingContext _localctx = new HeadingContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_heading);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(37);
			match(MAGIC_HEADING);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NodeContext extends ParserRuleContext {
		public NodeNameContext nodeName() {
			return getRuleContext(NodeNameContext.class,0);
		}
		public TerminalNode LEFT_PAREN() { return getToken(stfParser.LEFT_PAREN, 0); }
		public TerminalNode RIGHT_PAREN() { return getToken(stfParser.RIGHT_PAREN, 0); }
		public List<SpaceContext> space() {
			return getRuleContexts(SpaceContext.class);
		}
		public SpaceContext space(int i) {
			return getRuleContext(SpaceContext.class,i);
		}
		public NodeListContext nodeList() {
			return getRuleContext(NodeListContext.class,0);
		}
		public NodeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_node; }
	}

	public final NodeContext node() throws RecognitionException {
		NodeContext _localctx = new NodeContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_node);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(39);
			nodeName();
			setState(41);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(40);
				space();
				}
			}

			setState(43);
			match(LEFT_PAREN);
			setState(45);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				{
				setState(44);
				space();
				}
				break;
			}
			setState(48);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & 912L) != 0)) {
				{
				setState(47);
				nodeList();
				}
			}

			setState(51);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WS) {
				{
				setState(50);
				space();
				}
			}

			setState(53);
			match(RIGHT_PAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class SpaceContext extends ParserRuleContext {
		public List<TerminalNode> WS() { return getTokens(stfParser.WS); }
		public TerminalNode WS(int i) {
			return getToken(stfParser.WS, i);
		}
		public SpaceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_space; }
	}

	public final SpaceContext space() throws RecognitionException {
		SpaceContext _localctx = new SpaceContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_space);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(56); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(55);
					match(WS);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(58); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NodeNameContext extends ParserRuleContext {
		public List<TerminalNode> LETTER() { return getTokens(stfParser.LETTER); }
		public TerminalNode LETTER(int i) {
			return getToken(stfParser.LETTER, i);
		}
		public List<TerminalNode> DIGIT() { return getTokens(stfParser.DIGIT); }
		public TerminalNode DIGIT(int i) {
			return getToken(stfParser.DIGIT, i);
		}
		public NodeNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nodeName; }
	}

	public final NodeNameContext nodeName() throws RecognitionException {
		NodeNameContext _localctx = new NodeNameContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_nodeName);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			match(LETTER);
			setState(64);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LETTER || _la==DIGIT) {
				{
				{
				setState(61);
				_la = _input.LA(1);
				if ( !(_la==LETTER || _la==DIGIT) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				}
				setState(66);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NodeListContext extends ParserRuleContext {
		public List<NodeListItemContext> nodeListItem() {
			return getRuleContexts(NodeListItemContext.class);
		}
		public NodeListItemContext nodeListItem(int i) {
			return getRuleContext(NodeListItemContext.class,i);
		}
		public List<NodeListDelimContext> nodeListDelim() {
			return getRuleContexts(NodeListDelimContext.class);
		}
		public NodeListDelimContext nodeListDelim(int i) {
			return getRuleContext(NodeListDelimContext.class,i);
		}
		public NodeListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nodeList; }
	}

	public final NodeListContext nodeList() throws RecognitionException {
		NodeListContext _localctx = new NodeListContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_nodeList);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(67);
			nodeListItem();
			setState(73);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(68);
					nodeListDelim();
					setState(69);
					nodeListItem();
					}
					} 
				}
				setState(75);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,8,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NodeListDelimContext extends ParserRuleContext {
		public SpaceContext space() {
			return getRuleContext(SpaceContext.class,0);
		}
		public NodeListDelimContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nodeListDelim; }
	}

	public final NodeListDelimContext nodeListDelim() throws RecognitionException {
		NodeListDelimContext _localctx = new NodeListDelimContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_nodeListDelim);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(76);
			space();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NodeListItemContext extends ParserRuleContext {
		public NodeContext node() {
			return getRuleContext(NodeContext.class,0);
		}
		public TermContext term() {
			return getRuleContext(TermContext.class,0);
		}
		public NodeListItemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nodeListItem; }
	}

	public final NodeListItemContext nodeListItem() throws RecognitionException {
		NodeListItemContext _localctx = new NodeListItemContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_nodeListItem);
		try {
			setState(80);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(78);
				node();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(79);
				term();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TermContext extends ParserRuleContext {
		public IdentContext ident() {
			return getRuleContext(IdentContext.class,0);
		}
		public NumberContext number() {
			return getRuleContext(NumberContext.class,0);
		}
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public TermContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_term; }
	}

	public final TermContext term() throws RecognitionException {
		TermContext _localctx = new TermContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_term);
		try {
			setState(85);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LETTER:
				enterOuterAlt(_localctx, 1);
				{
				setState(82);
				ident();
				}
				break;
			case DIGIT:
			case DASH:
				enterOuterAlt(_localctx, 2);
				{
				setState(83);
				number();
				}
				break;
			case STRING:
				enterOuterAlt(_localctx, 3);
				{
				setState(84);
				string();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class StringContext extends ParserRuleContext {
		public List<TerminalNode> STRING() { return getTokens(stfParser.STRING); }
		public TerminalNode STRING(int i) {
			return getToken(stfParser.STRING, i);
		}
		public List<SpaceContext> space() {
			return getRuleContexts(SpaceContext.class);
		}
		public SpaceContext space(int i) {
			return getRuleContext(SpaceContext.class,i);
		}
		public List<TerminalNode> PLUS() { return getTokens(stfParser.PLUS); }
		public TerminalNode PLUS(int i) {
			return getToken(stfParser.PLUS, i);
		}
		public StringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string; }
	}

	public final StringContext string() throws RecognitionException {
		StringContext _localctx = new StringContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_string);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(87);
			match(STRING);
			setState(89);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				{
				setState(88);
				space();
				}
				break;
			}
			setState(98);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==PLUS) {
				{
				{
				setState(91);
				match(PLUS);
				setState(93);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==WS) {
					{
					setState(92);
					space();
					}
				}

				setState(95);
				match(STRING);
				}
				}
				setState(100);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IdentContext extends ParserRuleContext {
		public List<TerminalNode> LETTER() { return getTokens(stfParser.LETTER); }
		public TerminalNode LETTER(int i) {
			return getToken(stfParser.LETTER, i);
		}
		public List<TerminalNode> DIGIT() { return getTokens(stfParser.DIGIT); }
		public TerminalNode DIGIT(int i) {
			return getToken(stfParser.DIGIT, i);
		}
		public List<TerminalNode> DOT() { return getTokens(stfParser.DOT); }
		public TerminalNode DOT(int i) {
			return getToken(stfParser.DOT, i);
		}
		public List<TerminalNode> DASH() { return getTokens(stfParser.DASH); }
		public TerminalNode DASH(int i) {
			return getToken(stfParser.DASH, i);
		}
		public List<TerminalNode> PLUS() { return getTokens(stfParser.PLUS); }
		public TerminalNode PLUS(int i) {
			return getToken(stfParser.PLUS, i);
		}
		public IdentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ident; }
	}

	public final IdentContext ident() throws RecognitionException {
		IdentContext _localctx = new IdentContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_ident);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(102); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(101);
					match(LETTER);
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(104); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			setState(109);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 1984L) != 0)) {
				{
				{
				setState(106);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 1984L) != 0)) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				}
				setState(111);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NumberContext extends ParserRuleContext {
		public TerminalNode DASH() { return getToken(stfParser.DASH, 0); }
		public List<TerminalNode> DIGIT() { return getTokens(stfParser.DIGIT); }
		public TerminalNode DIGIT(int i) {
			return getToken(stfParser.DIGIT, i);
		}
		public TerminalNode DOT() { return getToken(stfParser.DOT, 0); }
		public NumberContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_number; }
	}

	public final NumberContext number() throws RecognitionException {
		NumberContext _localctx = new NumberContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_number);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(113);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==DASH) {
				{
				setState(112);
				match(DASH);
				}
			}

			setState(116); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(115);
				match(DIGIT);
				}
				}
				setState(118); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==DIGIT );
			setState(126);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==DOT) {
				{
				setState(120);
				match(DOT);
				setState(122); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(121);
					match(DIGIT);
					}
					}
					setState(124); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==DIGIT );
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\f\u0081\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0003\u0000\u001c\b\u0000\u0001\u0000\u0005"+
		"\u0000\u001f\b\u0000\n\u0000\f\u0000\"\t\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0003\u0002*\b\u0002"+
		"\u0001\u0002\u0001\u0002\u0003\u0002.\b\u0002\u0001\u0002\u0003\u0002"+
		"1\b\u0002\u0001\u0002\u0003\u00024\b\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0003\u0004\u00039\b\u0003\u000b\u0003\f\u0003:\u0001\u0004\u0001\u0004"+
		"\u0005\u0004?\b\u0004\n\u0004\f\u0004B\t\u0004\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0005\u0005H\b\u0005\n\u0005\f\u0005K\t\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0003\u0007Q\b\u0007"+
		"\u0001\b\u0001\b\u0001\b\u0003\bV\b\b\u0001\t\u0001\t\u0003\tZ\b\t\u0001"+
		"\t\u0001\t\u0003\t^\b\t\u0001\t\u0005\ta\b\t\n\t\f\td\t\t\u0001\n\u0004"+
		"\ng\b\n\u000b\n\f\nh\u0001\n\u0005\nl\b\n\n\n\f\no\t\n\u0001\u000b\u0003"+
		"\u000br\b\u000b\u0001\u000b\u0004\u000bu\b\u000b\u000b\u000b\f\u000bv"+
		"\u0001\u000b\u0001\u000b\u0004\u000b{\b\u000b\u000b\u000b\f\u000b|\u0003"+
		"\u000b\u007f\b\u000b\u0001\u000b\u0000\u0000\f\u0000\u0002\u0004\u0006"+
		"\b\n\f\u000e\u0010\u0012\u0014\u0016\u0000\u0002\u0001\u0000\u0007\b\u0001"+
		"\u0000\u0006\n\u0089\u0000\u0018\u0001\u0000\u0000\u0000\u0002%\u0001"+
		"\u0000\u0000\u0000\u0004\'\u0001\u0000\u0000\u0000\u00068\u0001\u0000"+
		"\u0000\u0000\b<\u0001\u0000\u0000\u0000\nC\u0001\u0000\u0000\u0000\fL"+
		"\u0001\u0000\u0000\u0000\u000eP\u0001\u0000\u0000\u0000\u0010U\u0001\u0000"+
		"\u0000\u0000\u0012W\u0001\u0000\u0000\u0000\u0014f\u0001\u0000\u0000\u0000"+
		"\u0016q\u0001\u0000\u0000\u0000\u0018\u0019\u0003\u0002\u0001\u0000\u0019"+
		"\u001b\u0003\u0004\u0002\u0000\u001a\u001c\u0003\u0006\u0003\u0000\u001b"+
		"\u001a\u0001\u0000\u0000\u0000\u001b\u001c\u0001\u0000\u0000\u0000\u001c"+
		" \u0001\u0000\u0000\u0000\u001d\u001f\u0003\u0004\u0002\u0000\u001e\u001d"+
		"\u0001\u0000\u0000\u0000\u001f\"\u0001\u0000\u0000\u0000 \u001e\u0001"+
		"\u0000\u0000\u0000 !\u0001\u0000\u0000\u0000!#\u0001\u0000\u0000\u0000"+
		"\" \u0001\u0000\u0000\u0000#$\u0005\u0000\u0000\u0001$\u0001\u0001\u0000"+
		"\u0000\u0000%&\u0005\u0001\u0000\u0000&\u0003\u0001\u0000\u0000\u0000"+
		"\')\u0003\b\u0004\u0000(*\u0003\u0006\u0003\u0000)(\u0001\u0000\u0000"+
		"\u0000)*\u0001\u0000\u0000\u0000*+\u0001\u0000\u0000\u0000+-\u0005\u0002"+
		"\u0000\u0000,.\u0003\u0006\u0003\u0000-,\u0001\u0000\u0000\u0000-.\u0001"+
		"\u0000\u0000\u0000.0\u0001\u0000\u0000\u0000/1\u0003\n\u0005\u00000/\u0001"+
		"\u0000\u0000\u000001\u0001\u0000\u0000\u000013\u0001\u0000\u0000\u0000"+
		"24\u0003\u0006\u0003\u000032\u0001\u0000\u0000\u000034\u0001\u0000\u0000"+
		"\u000045\u0001\u0000\u0000\u000056\u0005\u0003\u0000\u00006\u0005\u0001"+
		"\u0000\u0000\u000079\u0005\u000b\u0000\u000087\u0001\u0000\u0000\u0000"+
		"9:\u0001\u0000\u0000\u0000:8\u0001\u0000\u0000\u0000:;\u0001\u0000\u0000"+
		"\u0000;\u0007\u0001\u0000\u0000\u0000<@\u0005\u0007\u0000\u0000=?\u0007"+
		"\u0000\u0000\u0000>=\u0001\u0000\u0000\u0000?B\u0001\u0000\u0000\u0000"+
		"@>\u0001\u0000\u0000\u0000@A\u0001\u0000\u0000\u0000A\t\u0001\u0000\u0000"+
		"\u0000B@\u0001\u0000\u0000\u0000CI\u0003\u000e\u0007\u0000DE\u0003\f\u0006"+
		"\u0000EF\u0003\u000e\u0007\u0000FH\u0001\u0000\u0000\u0000GD\u0001\u0000"+
		"\u0000\u0000HK\u0001\u0000\u0000\u0000IG\u0001\u0000\u0000\u0000IJ\u0001"+
		"\u0000\u0000\u0000J\u000b\u0001\u0000\u0000\u0000KI\u0001\u0000\u0000"+
		"\u0000LM\u0003\u0006\u0003\u0000M\r\u0001\u0000\u0000\u0000NQ\u0003\u0004"+
		"\u0002\u0000OQ\u0003\u0010\b\u0000PN\u0001\u0000\u0000\u0000PO\u0001\u0000"+
		"\u0000\u0000Q\u000f\u0001\u0000\u0000\u0000RV\u0003\u0014\n\u0000SV\u0003"+
		"\u0016\u000b\u0000TV\u0003\u0012\t\u0000UR\u0001\u0000\u0000\u0000US\u0001"+
		"\u0000\u0000\u0000UT\u0001\u0000\u0000\u0000V\u0011\u0001\u0000\u0000"+
		"\u0000WY\u0005\u0004\u0000\u0000XZ\u0003\u0006\u0003\u0000YX\u0001\u0000"+
		"\u0000\u0000YZ\u0001\u0000\u0000\u0000Zb\u0001\u0000\u0000\u0000[]\u0005"+
		"\u0006\u0000\u0000\\^\u0003\u0006\u0003\u0000]\\\u0001\u0000\u0000\u0000"+
		"]^\u0001\u0000\u0000\u0000^_\u0001\u0000\u0000\u0000_a\u0005\u0004\u0000"+
		"\u0000`[\u0001\u0000\u0000\u0000ad\u0001\u0000\u0000\u0000b`\u0001\u0000"+
		"\u0000\u0000bc\u0001\u0000\u0000\u0000c\u0013\u0001\u0000\u0000\u0000"+
		"db\u0001\u0000\u0000\u0000eg\u0005\u0007\u0000\u0000fe\u0001\u0000\u0000"+
		"\u0000gh\u0001\u0000\u0000\u0000hf\u0001\u0000\u0000\u0000hi\u0001\u0000"+
		"\u0000\u0000im\u0001\u0000\u0000\u0000jl\u0007\u0001\u0000\u0000kj\u0001"+
		"\u0000\u0000\u0000lo\u0001\u0000\u0000\u0000mk\u0001\u0000\u0000\u0000"+
		"mn\u0001\u0000\u0000\u0000n\u0015\u0001\u0000\u0000\u0000om\u0001\u0000"+
		"\u0000\u0000pr\u0005\t\u0000\u0000qp\u0001\u0000\u0000\u0000qr\u0001\u0000"+
		"\u0000\u0000rt\u0001\u0000\u0000\u0000su\u0005\b\u0000\u0000ts\u0001\u0000"+
		"\u0000\u0000uv\u0001\u0000\u0000\u0000vt\u0001\u0000\u0000\u0000vw\u0001"+
		"\u0000\u0000\u0000w~\u0001\u0000\u0000\u0000xz\u0005\n\u0000\u0000y{\u0005"+
		"\b\u0000\u0000zy\u0001\u0000\u0000\u0000{|\u0001\u0000\u0000\u0000|z\u0001"+
		"\u0000\u0000\u0000|}\u0001\u0000\u0000\u0000}\u007f\u0001\u0000\u0000"+
		"\u0000~x\u0001\u0000\u0000\u0000~\u007f\u0001\u0000\u0000\u0000\u007f"+
		"\u0017\u0001\u0000\u0000\u0000\u0014\u001b )-03:@IPUY]bhmqv|~";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}