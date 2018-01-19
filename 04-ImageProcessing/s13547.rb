require 'opencv'

module TemplateMatcher
  # 与えられた引数からテンプレートマッチングを行い、結果を画像で出力する
  #
  # - 画像はこの template_matcher.rb が配置されている場所と同じ階層に imgs/ というディレクトリを作り、その中へ配置する
  #
  # base_img_name      : マッチングされる画像の名前(拡張子含む)
  # template_img_name  : テンプレート画像の名前(拡張子含む)
  # matching_operation : 類似度計算手法
  #                      - OpenCV::CV_TM_SQDIFF : 輝度差の二乗和(デフォルト)
  #                      - OpenCV::CV_TM_CCORR  : 相互相関
  #                      - OpenCV::CV_TM_CCOEFF : 相関係数
  #                      - それぞれについて正規化したものも存在する(CV_TM_CCORR_NORMEDなど)
  def self.operate(base_img_name, template_img_name,
                   matching_operation = OpenCV::CV_TM_SQDIFF)
    base_img = OpenCV::IplImage.load('./images/' + base_img_name)
    template = OpenCV::IplImage.load('./images/' + template_img_name)

    result = base_img.match_template(template, matching_operation)

    # マッチングした部分(輝度差の二乗和における最小値)の座標を求める
    matched_from = result.min_max_loc[2]
    matched_to   = OpenCV::CvPoint.new(matched_from.x + template.width,
                                       matched_from.y + template.height)

    # マッチングした部分の座標を表示
    puts("#{template_img_name} matched from " \
         "x:#{matched_from.x} y:#{matched_from.y} in #{base_img_name}")

    # マッチングした部分を囲い、画像として保存する
    base_img.rectangle(matched_from, matched_to, color: OpenCV::CvScalar::Red)
            .save_image('./imgs/matched_' + base_img_name)
  end
end

########## main ##########
TemplateMatcher.operate('img_1.bmp', 'Timg_1.bmp')
TemplateMatcher.operate('img_2.bmp', 'Timg_2.bmp')
