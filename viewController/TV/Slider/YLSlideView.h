
/*
 
   YLSlideView 是 UIScrollView 的一个重用视图，新闻类型客户端比较常见这种做法
   YLSlideCell
   YLSlideTitleView
   YLCache
 */


#import <UIKit/UIKit.h>

//#import "YLSlideCell.h"


@class YLSlideView;
@class YLSlideTitleView;

#pragma mark YLSlideViewDelegate

/*YLSlideView delegate 方法，设置重用 Cell 和需要创建的页面数 ，在此没有区分 
 dataSource 和 view delegate 。统一实现 YLSlideViewDelegate
 */
@protocol YLSlideViewDelegate <NSObject>

@required
/**
 *  需要创建的页面数量
 */
- (NSInteger)columnNumber;

/**
 *  创建Cell方法，使用重用机制。目前在此处只针对UITableView，有特殊需求的可自行进行修改
 *
 *  @param slideView
 *  @param index     页面相对应的索引路径
 *
 *  @return Cell
 */
//- (YLSlideCell *)slideView:(YLSlideView *)slideView
//     cellForRowAtIndex:(NSUInteger)index;

-(TVTable *)slideView:(YLSlideView *)slideView cellForRowAtIndex:(NSUInteger)index;




/**
 *  当 cell 初始化完成时调用
 *  可以做预加载显示缓存数据
 *
 *  @param cell
 *  @param index
 */
//- (void)slideViewInitiatedComplete:(YLSlideCell*)cell forIndex:(NSUInteger)index;
- (void)slideViewInitiatedComplete:(TVTable *)cell forIndex:(NSUInteger)index;
@optional

/**
 *  返回当前页码
 *
 *  @param index 页码
 */
//- (void)slideVisibleView:(YLSlideCell*)cell forIndex:(NSUInteger)index;
- (void)slideVisibleView:(TVTable *)cell forIndex:(NSUInteger)index;

@end

#pragma mark YLSlideView
@interface YLSlideView : UIView

/*做这种类型自定义需求比较高，在此就没提供更多方便的接口。
 mainScrollview 装栽所有Cell 的一个集合容器
 slideTitleView titles 栏目的容器集合
 */
@property (nonatomic,strong)UIScrollView     *mainScrollview;
@property (nonatomic,strong)YLSlideTitleView *slideTitleView;
@property (nonatomic,strong)UIImageView * triangleView;
@property (nonatomic,strong) UIView * lineview;
// default NO 是否显示滚动条
@property (nonatomic,assign)BOOL              showsScrollViewHorizontalScrollIndicator;

@property (nonatomic,weak) id<YLSlideViewDelegate>delegate;

/**
 *  初始化方法
 *
 *  @param frame
 *  @param titles headView的内容标题
 *
 *  @return
 */
//- (instancetype)initWithFrame:(CGRect)frame forTitles:(NSArray *)titles;
- (instancetype)initWithFrame:(CGRect)frame forTitles:(NSMutableArray *)titles;

/**
 *  重置数据
 */
- (void)reloadData;

/**
 *  重用
 *
 *  @return 可重用的Cell
 */
//- (YLSlideCell*)dequeueReusableCell;
- (TVTable*)dequeueReusableCell;
@end

