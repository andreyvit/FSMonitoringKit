#import <Foundation/Foundation.h>


@class FSTreeFilter;


@interface FSTree : NSObject {
    NSString *_rootPath;
    FSTreeFilter *_filter;
    struct FSTreeItem *_items;
    NSInteger _count;
    NSTimeInterval _buildTime;
    NSMutableArray *_folders;
}

- (id)initWithPath:(NSString *)path filter:(FSTreeFilter *)filter;

@property (nonatomic, readonly, copy) NSString *rootPath;
@property (nonatomic, readonly) NSTimeInterval buildTime;

- (NSSet *)differenceFrom:(FSTree *)previous;

- (BOOL)containsFileNamed:(NSString *)fileName;
- (NSString *)pathOfFileNamed:(NSString *)fileName;
- (NSArray *)pathsOfFilesNamed:(NSString *)fileName;
- (NSArray *)pathsOfFilesMatching:(BOOL (^)(NSString *name))filter;
- (NSString *)pathOfBestFileMatchingPathSuffix:(NSString *)pathSuffix preferringSubtree:(NSString *)subtreePath;

@property(nonatomic, readonly, strong) NSArray *filePaths;

@property(nonatomic, readonly, strong) NSArray *folderPaths;

@end
