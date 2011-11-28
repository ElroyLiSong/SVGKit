//
//  SVGElement.h
//  SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>

@class SVGDocument;

@interface SVGElement : NSObject {
  @private
	NSMutableArray *_children;
}

/*! This is used when generating CALayer objects, to store the id of the SVGElement that created the CALayer */
#define kSVGElementIdentifier @"SVGElementIdentifier"

@property (nonatomic, readonly) __weak SVGDocument *document;

@property (nonatomic, readonly) NSArray *children;
@property (nonatomic, readonly, copy) NSString *stringValue;
@property (nonatomic, readonly) NSString *localName;

@property (nonatomic, readwrite, retain) NSString *identifier; // 'id' is reserved

+ (BOOL)shouldStoreContent; // to optimize parser, default is NO

- (id)initWithDocument:(SVGDocument *)aDocument name:(NSString *)name;

- (void)loadDefaults; // should be overriden to set element defaults

@end

@protocol SVGLayeredElement < NSObject >

/*!
 NB: the returned layer has - as its "name" property - the "identifier" property of the SVGElement that created it;
 but that can be overwritten by applications (for valid reasons), so we ADDITIONALLY store the identifier into a
 custom key - kSVGElementIdentifier - on the CALayer. Because it's a custom key, it's (almost) guaranteed not to be
 overwritten / altered by other application code
 */
- (CALayer *)newLayer;
- (void)layoutLayer:(CALayer *)layer;

@end
